#include "TrafficSim.h"
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
		cout << "Filed to open file: " << inputFile << endl;
		cout << "...exiting" << endl;
		exit(1);
	} else {
		cout << inputFile << " was successfully opened." << endl;
	}

	while(infile >> input)
	getline(infile, line);
	cout << line << endl;





	cin >> stopper;
}