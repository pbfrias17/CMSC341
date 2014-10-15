/*****************************************
** File:    TrafficSim.cpp
** Project: Project 1
** Author:  Paolo Frias
** Date:    9/30/2014
** Section: 03
** E-mail:  pfrias2@umbc.edu

**   This file contains the implementation for the TrafficSim class
**TrafficSim is the main file that handles the traffic light simulation
**using queues and linked lists
***********************************************/

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

void TrafficSim::DoRun() {
	string line;
	Result* resultList;
	resultList = new Result;
<<<<<<< HEAD
	//Result* iterator;
	cout << "Opening: " << inputFile << endl;
=======
	resultList->setVehicle(ResultVehicle());
	resultList->setNext(NULL);
	Result* iterator;
	iterator = resultList;
	iterator->setNext(new Result);
	iterator = iterator->getNext();
	iterator->setVehicle(ResultVehicle());
	iterator->setNext(NULL);
>>>>>>> origin/master

	ifstream infile;
	infile.open(inputFile.c_str(), ios_base::in);

	if (infile.fail()) {
		cout << "Failed to open file: " << inputFile << endl;
		cout << "...exiting" << endl;
		exit(1);
	}

	IntersectionFlowRate IFR = IntersectionFlowRate();

	//Have to import the info from the input file into
	//the IntersectionFlowRate object
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
		}
			counter++;
	}

	//Each lane starts with 2 cars
	for (int i = 0; i < 2; i++) {
		northbound.push(Vehicle('c', 0));
		southbound.push(Vehicle('c', 0));
		eastbound.push(Vehicle('c', 0));
		westbound.push(Vehicle('c', 0));
	}

	//Calculate when each lane gets a new vehicle
	int northCarPushTime = 60 / IFR.getNorthCarRate();
	int southCarPushTime = 60 / IFR.getSouthCarRate();
	int eastCarPushTime = 60 / IFR.getEastCarRate();
	int westCarPushTime = 60 / IFR.getWestCarRate();
	int northTruckPushTime = 60 / IFR.getNorthTruckRate();
	int southTruckPushTime = 60 / IFR.getSouthTruckRate();
	int eastTruckPushTime = 60 / IFR.getEastTruckRate();
	int westTruckPushTime = 60 / IFR.getWestTruckRate();

	//For keeping track of time to push
	int nbCars = 0;
	int nbTrucks = 0;
	int sbCars = 0;
	int sbTrucks = 0;
	int ebCars = 0;
	int ebTrucks = 0;
	int wbCars = 0;
	int wbTrucks = 0;

	//Keep track of how long lights are green
	int NSDuration = 0;
	int EWDuration = 0;
	bool NSGreen = true;

	//start the 120 second loop
	for (int i = 0; i <= 120; i++) {

		//Do not run simulation until second 1
		//Still want to print intersection at clock 1 
		if (i != 0) {
			/********************/
			/* POP OUTTA QUEUES */
			/********************/
			if (NSGreen) {
				if (!northbound.empty()) {
					Vehicle nbVehicle = northbound.front();
					int timeSpent = i - nbVehicle.getTimeEntered();
					if (nbVehicle.getType() == 'c') {
						iterator->setVehicle(ResultVehicle(nbVehicle.getType(), timeSpent));
						iterator->setNext(new Result);
						iterator = iterator->getNext();
						iterator->setNext(NULL);
						northbound.pop();
					} else {
						static int nbTimer = 1;

						if (nbTimer == 0) {
							iterator->setVehicle(ResultVehicle(nbVehicle.getType(), timeSpent));
							iterator->setNext(new Result);
							iterator = iterator->getNext();
							iterator->setNext(NULL);
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
					int timeSpent = i - sbVehicle.getTimeEntered();
					if (sbVehicle.getType() == 'c') {
						iterator->setVehicle(ResultVehicle(sbVehicle.getType(), timeSpent));
						iterator->setNext(new Result);
						iterator = iterator->getNext();
						iterator->setNext(NULL);
						southbound.pop();
					}
					else {
						static int sbTimer = 1;

						if (sbTimer == 0) {
							iterator->setVehicle(ResultVehicle(sbVehicle.getType(), timeSpent));
							iterator->setNext(new Result);
							iterator = iterator->getNext();
							iterator->setNext(NULL);
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
					int timeSpent = i - ebVehicle.getTimeEntered();
					if (ebVehicle.getType() == 'c') {
						iterator->setVehicle(ResultVehicle(ebVehicle.getType(), timeSpent));
						iterator->setNext(new Result);
						iterator = iterator->getNext();
						iterator->setNext(NULL);
						eastbound.pop();
					}
					else {
						static int ebTimer = 1;

						if (ebTimer == 0) {
							iterator->setVehicle(ResultVehicle(ebVehicle.getType(), timeSpent));
							iterator->setNext(new Result);
							iterator = iterator->getNext();
							iterator->setNext(NULL);
							eastbound.pop();
							ebTimer = 1; // reset timer for next truck
						}
						else {
							ebTimer--;
						}
					}
				}
				if (!westbound.empty()) {
					Vehicle wbVehicle = westbound.front();
					int timeSpent = i - wbVehicle.getTimeEntered();
					if (wbVehicle.getType() == 'c') {
						iterator->setVehicle(ResultVehicle(wbVehicle.getType(), timeSpent));
						iterator->setNext(new Result);
						iterator = iterator->getNext();
						iterator->setNext(NULL);
						westbound.pop();
					}
					else {
						static int wbTimer = 1;

						if (wbTimer == 0) {
							iterator->setVehicle(ResultVehicle(wbVehicle.getType(), timeSpent));
							iterator->setNext(new Result);
							iterator = iterator->getNext();
							iterator->setNext(NULL);
							westbound.pop();
							wbTimer = 1; // reset timer for next truck
						}
						else {
							wbTimer--;
						}
					}
				}
				EWDuration++;
			}

			//Light changes based on these conditionals
			if (EWDuration >= 30) {
				NSGreen = true;
				EWDuration = 0;
			}
			else {
				if (EWDuration >= 10) {
					if (eastbound.empty() && westbound.empty()) {
						NSGreen = true;
						EWDuration = 0;
					}
					else {
						NSGreen = false;
						NSDuration = 0;
					}
				}
				if (EWDuration < 10 && EWDuration > 0) {
					NSGreen = false;
					NSDuration = 0;
				}
				if (NSDuration >= 60) {
					NSGreen = false;
					NSDuration = 0;
				}
				else {
					if (NSDuration >= 30) {
						if (northbound.empty() && southbound.empty()) {
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

		//Now print the intersection
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
				cout << "EB         " << southbound.front().getType() << "\n";
			else
				cout << "\t   x\n";
		}

		cout << ebAmt << "  ";
		if (ebAmt >= 10)
			cout << " ";
		else
			cout << "  ";

		for (int eb = 1; eb <= 6 - ebAmt; eb++) {
			cout << " ";
		}
		for (int eb = 1; eb <= ebAmt; eb++) {
			if (eb == ebAmt)
				cout << eastbound.front().getType();
			else
				cout << "x";
			if (eb == 6)
				break;
		}

		cout << " ";
		for (int wb = 1; wb <= wbAmt; wb++) {
			if (wb == 1)
				cout << westbound.front().getType();
			else
				cout << "x";
		}
		for (int wb = 1; wb <= 6 - wbAmt; wb++) {
			cout << " ";
		}
		cout << "  " << wbAmt;

		cout << "\n";
		for (int nb = 1; nb <= nbAmt; nb++) {
			if (nb == 1)
				cout << "\t   " << northbound.front().getType() << "\tWB\n";
			else
				cout << "\t   x\n";
		}
		if (nbAmt == 0)
			cout << "\t  \t    WB";
		for (int nb = 1; nb < 6 - nbAmt - 1; nb++) {
			cout << "\n";
		}
		cout << "\n     SB " << sbAmt << "\n";

		cout << "at clock: " << i << "\n---------------------------\n";

	}
	int count = 0;
	int car_count = 0;
	int truck_count = 0;
	int overallTime = 0;
	iterator = resultList;
	if (iterator != 0) {
		while (iterator->getNext() != NULL) {
			ResultVehicle resultVehicle = iterator->getVehicle();
			if (resultVehicle.getType() == 'c')
				car_count++;
			else
				truck_count++;

			int timeSpent = resultVehicle.getTimeSpent();
			overallTime += timeSpent;
			iterator = iterator->getNext();
			count++;

		}
		//For the last element of the linked list
		ResultVehicle resultVehicle = iterator->getVehicle();
		if (resultVehicle.getType() == 'c')
			car_count++;
		else
			truck_count++;
		
		count++;
	}

	double timePer = overallTime / count;

	cout << "\n::| Simulation Statistics |::\n";
	cout << "Amount of vehicles that crossed intersection: " << count << "\n";
	cout << "Amount of cars that crossed intersection: " << car_count << "\n";
	cout << "Amount of trucks that crossed intersection: " << truck_count << "\n";
	cout << "Average amount of time each vehicle spent waiting: " << timePer << " seconds\n";

	delete resultList;
	resultList = NULL;

	delete iterator;
	iterator = NULL;
}