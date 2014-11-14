#include "ProbingSimulation.h"
#include <fstream>
#include <iostream>


using namespace std;

ProbingSimulation::ProbingSimulation() {}

ProbingSimulation::ProbingSimulation(string inputFilename, int N, int interval, int M)
:m_inputFile(inputFilename), m_totalAmount(N), m_interval(interval), m_hashSize(M) {
	
	randInts = new int[m_totalAmount];

	LinearHashTable = HashTable(m_hashSize);

}

ProbingSimulation::~ProbingSimulation() {
	//randInts = NULL;
	//delete[] randInts;
}

void ProbingSimulation::ReadInput() {
	cout << "Reading in random integers from " << m_inputFile << endl;

	ifstream inputFile;
	inputFile.open(m_inputFile.c_str(), ios_base::in);

	if(inputFile.fail()) {
		cout << "Failed to open file: " << m_inputFile << endl;
		cout << "...exiting" << endl;

		exit(1);
	} else {
		string randInt;
		int i = 0;
		while(inputFile >> randInt) {
			randInts[i] = atoi(randInt.c_str());
			i++;
		}
	}
}

void ProbingSimulation::RunTests() {

	//LinearHashTable.PrintTable();

	cout << "Testing Linear:\n";
	LinearHashTable.LinearProbe(randInts);
	cout << "Testing Quadratic:\n";
	QuadraticHashTable.QuadraticProbe(randInts);
}