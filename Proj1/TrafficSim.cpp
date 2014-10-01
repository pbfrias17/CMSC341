#include "TrafficSim.h"
#include "IntersectionFlowRate.h"
#include "Vehicle.h"
#include "ResultVehicle.h"
#include "Result.h"
#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;


TrafficSim::TrafficSim()
:inputFile("inputDefault.txt") {}

TrafficSim::TrafficSim(string file)
:inputFile(file) {}

int TrafficSim::getNSDuration() {
	return NSDuration;
}

int TrafficSim::getEWDuration() {
	return EWDuration;
}

void TrafficSim::setNSDuration(int duration) {
	NSDuration = duration;
}

void TrafficSim::setEWDuration(int duration) {
	EWDuration = duration;
}


void TrafficSim::DoRun() {
	string line;
	Result* resultList;
	resultList = new Result;
	Result* iterator;

	ifstream infile;
	infile.open(inputFile.c_str(), ios_base::in);

	if (infile.fail()) {
		cout << "Failed to open file: " << inputFile << endl;
		cout << "...exiting" << endl;
		exit(1);
	}

	IntersectionFlowRate IFR = IntersectionFlowRate();

	int counter = 0;
	while (infile >> line) {
		//getline(infile, line);
		cout << line << endl;
		switch (counter) {
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

			counter++;
		}

	}

	for (int i = 0; i < 2; i++) {
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

	int NSDuration = 0; //Keep track of how long lights are green
	int EWDuration = 0;
	bool NSGreen = true;


	// for our linked list of vehicles passing the intersection


	//cout << "trucks will enter eb lane every " << eastTruckPushTime << " seconds\n";

	for (int i = 0; i <= 40; i++) {

		//Do not run simulation until second 1
		//Still want to print intersection at clock 1 
		if (i != 0) {
			/********************/
			/* POP OUTTA QUEUES */
			/********************/
			
			if (NSGreen) {
				if (!northbound.empty()) {
					Vehicle nbVehicle = northbound.front();
					if (nbVehicle.getType() == 'c') {
						Vehicle result = northbound.front();
						resultList->setVehicle(ResultVehicle(result.getType(), 20));
						northbound.pop();
					}
					else {
						static int nbTimer = 1;

						if (nbTimer == 0) {
							northbound.pop();
							nbTimer = 1; // reset timer for next truck
						}
						else {
							nbTimer--;
						}
					}
				}
				if (!southbound.empty()) {
					Vehicle sbVehicle = southbound.front();
					if (sbVehicle.getType() == 'c') {
						southbound.pop();
					}
					else {
						static int sbTimer = 1;

						if (sbTimer == 0) {
							southbound.pop();
							sbTimer = 1; //reset timer for next truck
						}
						else {
							sbTimer--;
						}
					}
				}
				NSDuration++;
			}
			else {

				// if EW green
				if (!eastbound.empty()) {
					Vehicle ebVehicle = eastbound.front();
					if (ebVehicle.getType() == 'c') {
						eastbound.pop();
					}
					else {
						static int ebTimer = 1;

						if (ebTimer == 0) {
							eastbound.pop();
							ebTimer = 1; // reset timer for next truck
						} else {
							ebTimer--;
						}
					}
				}
				if (!westbound.empty()) {
					Vehicle wbVehicle = westbound.front();
					if (wbVehicle.getType() == 'c') {
						westbound.pop();
					} else {
						static int wbTimer = 1;

						if (wbTimer == 0) {
							westbound.pop();
							wbTimer = 1; // reset timer for next truck
						} else {
							wbTimer--;
						}
					}
				}
				EWDuration++;
			}

			//Light changes based on these conditionals
			//MAKE CONSTANTS! NO MAGIC NUMBERS!
			if (EWDuration >= 30) {
				cout << "NSGreen because EW was green for " << EWDuration << "seconds\n";
				NSGreen = true;
				EWDuration = 0;
			}
			else {
				if (EWDuration >= 10) {
					if (eastbound.empty() && westbound.empty()) {
						cout << "NSGreen because EW was green for " << EWDuration << "seconds with no cars in their lanes!!\n";
						NSGreen = true;
						EWDuration = 0;
					}
					else {
						cout << "NSRed because EW not at 30 seconds yet but still has cars in their lanes\n";
						NSGreen = false;
						NSDuration = 0;
					}
				}
				if (EWDuration < 10 && EWDuration > 0) {
					cout << "NSGreen because EW must be green for atleast 10 seconds\n";
					NSGreen = false;
					NSDuration = 0;
				}
				if (NSDuration >= 60) {
					cout << "NSRed cuz NS can only be green for 60 seconds max\n";
					NSGreen = false;
					NSDuration = 0;
				}
				else {
					if (NSDuration >= 30) {
						if (northbound.empty() && southbound.empty()) {
							cout << "NSRed cuz NS was green for " << NSDuration << " seconds and is now empty\n";
							NSGreen = false;
							NSDuration = 0;
						}
					}
				}
			}


			/********************/
			/* PUSH INTO QUEUES */
			/********************/
			// cars arrive first
			if (i == northCarPushTime) {
				nbCars++;
				northCarPushTime += northCarPushTime / nbCars;
				northbound.push(Vehicle('c', i));
			}
			if (i == southCarPushTime) {
				sbCars++;
				southCarPushTime += southCarPushTime / sbCars;
				southbound.push(Vehicle('c', i));
			}
			if (i == eastCarPushTime) {
				ebCars++;
				eastCarPushTime += eastCarPushTime / ebCars;
				eastbound.push(Vehicle('c', i));
			}
			if (i == westCarPushTime) {
				wbCars++;
				westCarPushTime += westCarPushTime / wbCars;
				westbound.push(Vehicle('c', i));
			}
			// then trucks arrive
			if (i == northTruckPushTime) {
				nbTrucks++;
				northTruckPushTime += northTruckPushTime / nbTrucks;
				northbound.push(Vehicle('t', i));
			}
			if (i == southTruckPushTime) {
				sbTrucks++;
				southTruckPushTime += southTruckPushTime / sbTrucks;
				southbound.push(Vehicle('t', i));
			}
			if (i == eastTruckPushTime) {
				ebTrucks++;
				eastTruckPushTime += eastTruckPushTime / ebTrucks;
				eastbound.push(Vehicle('t', i));
			}
			if (i == westTruckPushTime) {
				wbTrucks++;
				westTruckPushTime += westTruckPushTime / wbTrucks;
				westbound.push(Vehicle('t', i));
			}
		}


		int sbAmt = southbound.size();
		int ebAmt = eastbound.size();
		int wbAmt = westbound.size();
		int nbAmt = northbound.size();

		cout << "     SB " << sbAmt;
		for (int sb = 1; sb <= 6 - sbAmt; sb++) {
			if (sb == 6)
				cout << "EB\n";
			else
				cout << "\n";
		}
		for (int sb = 1; sb <= sbAmt; sb++) {
			if (sb == sbAmt)
				cout << "EB        " << southbound.front().getType() << "\n";
			else
				cout << "\t  x\n";
		}

		cout << ebAmt << "  ";
		for (int eb = 1; eb <= 6 - sbAmt; eb++) {
			cout << " ";
		}
		for (int eb = 1; eb <= ebAmt; eb++) {
			if (eb == ebAmt)
				cout << eastbound.front().getType();
			else
				cout << "x";
		}

		cout << " ";
		for (int wb = 1; wb <= wbAmt; wb++) {
			if (wb == 1)
				cout << westbound.front().getType();
			else
				cout << "x";
		}

		cout << "\n";
		for (int nb = 1; nb <= nbAmt; nb++) {
			if (nb == 1)
				cout << "\t  " << northbound.front().getType() << "\tWB\n";
			else
				cout << "\t  x\n";
		}
		if (nbAmt == 0)
			cout << "\t  \tWB";
		for (int nb = 1; nb < 6 - nbAmt - 1; nb++) {
			cout << "\n";
		}

		cout << "at clock: " << i << "\n---------------------------\n";

	}

	// Here is our linked list (temp)



	delete resultList;
	resultList = NULL;

	// Use only if IFR will be dynamic
	//delete IFR;
	//IFR = NULL;
	cin >> stopper;
	
}