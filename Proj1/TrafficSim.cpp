#include "TrafficSim.h"
#include "IntersectionFlowRate.h"
#include <iostream>
#include <cstdlib>
using namespace std;


TrafficSim::TrafficSim()
:inputFile("inputDefault.txt") {}

TrafficSim::TrafficSim(string file)
:inputFile(file) {}

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
	
	IntersectionFlowRate *IFR = new IntersectionFlowRate();

	int counter = 0;
	while (infile >> line) {
		//getline(infile, line);
		cout << line << endl;
		switch (counter) {
			case 1:
				IFR->setEastCarRate(atoi(line.c_str()));
				break;
			case 2:
				IFR->setEastTruckRate(atoi(line.c_str()));
				break;
			case 4:
				IFR->setWestCarRate(atoi(line.c_str()));
				break;
			case 5:
				IFR->setWestTruckRate(atoi(line.c_str()));
				break;
			case 7:
				IFR->setEastCarRate(atoi(line.c_str()));
				break;
			case 8:
				IFR->setEastCarRate(atoi(line.c_str()));
				break;
			case 10:
				IFR->setEastCarRate(atoi(line.c_str()));
				break;
			case 11:
				IFR->setEastCarRate(atoi(line.c_str()));
				break;
			default:
				cout << "Not a flow rate" << endl;
		}
		counter++;
	}
	
	cin >> stopper;

	delete IFR;
	IFR = NULL;

}