#include "TrafficSim.h"
#include "IntersectionFlowRate.h"
#include "Vehicle.h"
#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;


TrafficSim::TrafficSim()
:inputFile("inputDefault.txt") {}

TrafficSim::TrafficSim(string file)
:inputFile(file) {}

bool TrafficSim::NSGreen() {

}

void TrafficSim::DoRun() {
	string line;
	cout << "Opening: " << inputFile << endl;

	ifstream infile;
	infile.open(inputFile.c_str(), ios_base::in);

	if(infile.fail()) {
		cout << "Failed to open file: " << inputFile << endl;
		cout << "...exiting" << endl;
		cin >> stopper;
		exit(1);
	} else {
		cout << inputFile << " was successfully opened." << endl;
	}

	IntersectionFlowRate IFR = IntersectionFlowRate();

	int counter = 0;
	while(infile >> line) {
		//getline(infile, line);
		cout << line << endl;
		switch(counter) {
		case 1:
			IFR.setNorthCarRate(atoi(line.c_str()));
			cout << IFR.getNorthCarRate();
			break;
		case 2:
			IFR.setNorthTruckRate(atoi(line.c_str()));
			break;
		case 4:
			IFR.setSouthCarRate(atoi(line.c_str()));
			break;
		case 5:
			IFR.setSouthTruckRate(atoi(line.c_str()));
			break;
		case 7:
			IFR.setEastCarRate(atoi(line.c_str()));
			break;
		case 8:
			IFR.setEastTruckRate(atoi(line.c_str()));
			cout << IFR.getEastTruckRate();
			break;
		case 10:
			IFR.setWestCarRate(atoi(line.c_str()));
			break;
		case 11:
			IFR.setWestTruckRate(atoi(line.c_str()));
			break;
		default:
			cout << "Not a flow rate" << endl;
		}
		counter++;
	}

	cout << "Input file now stored into IntersectionFlowRate: Starting sim... \n";

	//initialize queues (2 cars start in each lane)
	queue <Vehicle> northbound;
	queue <Vehicle> southbound;
	queue <Vehicle> eastbound;
	queue <Vehicle> westbound;

	///Will need this later doe
	for(int i = 0; i < 2; i++) {
		northbound.push(Vehicle('c', 0));
		southbound.push(Vehicle('c', 0));
		eastbound.push(Vehicle('c', 0));
		westbound.push(Vehicle('c', 0));
	}

	int northCarPushTime = 60 / IFR.getNorthCarRate();
	int southCarPushTime = 60 / IFR.getSouthCarRate();
	int eastCarPushTime = 60 / IFR.getEastCarRate();
	int westCarPushTime = 60 / IFR.getWestCarRate();
	int northTruckPushTime = 60 / IFR.getNorthTruckRate();
	int southTruckPushTime = 60 / IFR.getSouthTruckRate();
	int eastTruckPushTime = 60 / IFR.getEastTruckRate();
	int westTruckPushTime = 60 / IFR.getWestTruckRate();

	// for keeping track of time to push
	int nbCars = 0;
	int nbTrucks = 0;
	int sbCars = 0;
	int sbTrucks = 0;
	int ebCars = 0;
	int ebTrucks = 0;
	int wbCars = 0;
	int wbTrucks = 0;

	cout << "trucks will enter eb lane every " << eastTruckPushTime << " seconds\n";

	for(int i = 1; i <= 65; i++) {
		int NSTimer = 0; // Must keep track of how long it's been since car has crossed each intersection
		int EWTimer = 0;
		cout << "Clock at: " << i << endl;

		/********************/
		/* POP OUTTA QUEUES */
		/********************/
		// if NS green
		if(!northbound.empty()) {
			Vehicle nbVehicle = northbound.front();
			if(nbVehicle.getType() == 'c') {
				northbound.pop();
			} else {
				static int nbTimer = 1;

				if(nbTimer == 0) {
					northbound.pop();
					nbTimer = 1; // reset timer for next truck
				} else {
					nbTimer--;
				}
			}
		}
		if(!southbound.empty()) {
			Vehicle sbVehicle = southbound.front();
			if(sbVehicle.getType() == 'c') {
				southbound.pop();
			} else {
				static int sbTimer = 1;

				if(sbTimer == 0) {
					southbound.pop();
					sbTimer = 1; // reset timer for next truck
				} else {
					sbTimer--;
				}
			}
		}
		// if EW green
		if(!eastbound.empty()) {
			Vehicle ebVehicle = eastbound.front();
			if(ebVehicle.getType() == 'c') {
				eastbound.pop();
			} else {
				static int ebTimer = 1;

				if(ebTimer == 0) {
					eastbound.pop();
					ebTimer = 1; // reset timer for next truck
				} else {
					ebTimer--;
				}
			}
		}
		if(!westbound.empty()) {
			Vehicle wbVehicle = westbound.front();
			if(wbVehicle.getType() == 'c') {
				westbound.pop();
			} else {
				static int wbTimer = 1;

				if(wbTimer == 0) {
					westbound.pop();
					wbTimer = 1; // reset timer for next truck
				} else {
					wbTimer--;
				}
			}
		}


		/********************/
		/* PUSH INTO QUEUES */
		/********************/
		// cars arrive first
		if(i == northCarPushTime) {
			nbCars++;
			northCarPushTime += northCarPushTime / nbCars;
			northbound.push(Vehicle('c', i));
		}
		if(i == southCarPushTime) {
			sbCars++;
			southCarPushTime += southCarPushTime / sbCars;
			southbound.push(Vehicle('c', i));
		}
		if(i == eastCarPushTime) {
			ebCars++;
			eastCarPushTime += eastCarPushTime / ebCars;
			eastbound.push(Vehicle('c', i));
		}
		if(i == westCarPushTime) {
			wbCars++;
			westCarPushTime += westCarPushTime / wbCars;
			westbound.push(Vehicle('c', i));
		}
		// then trucks arrive
		if(i == northTruckPushTime) {
			nbTrucks++;
			northTruckPushTime += northTruckPushTime / nbTrucks;
			northbound.push(Vehicle('t', i));
		}
		if(i == southTruckPushTime) {
			sbTrucks++;
			southTruckPushTime += southTruckPushTime / sbTrucks;
			southbound.push(Vehicle('t', i));
		}
		if(i == eastTruckPushTime) {
			ebTrucks++;
			eastTruckPushTime += eastTruckPushTime / ebTrucks;
			eastbound.push(Vehicle('t', i));
		}
		if(i == westTruckPushTime) {
			wbTrucks++;
			westTruckPushTime += westTruckPushTime / wbTrucks;
			westbound.push(Vehicle('t', i));
		}

		// create a printIntersection() function to do this!!!
		cout << "\tnorthbound: " << northbound.size();
		cout << "\tsouthbound: " << southbound.size();
		cout << "\teastbound: " << eastbound.size();
		cout << "\twestbound: " << westbound.size() << endl << endl;
		////////////////////////////////////////////////////////////

	}


	// Use only if IFR will be dynamic
	//delete IFR;
	//IFR = NULL;
	cin >> stopper;
}