#include "ProbingSimulation.h"
#include <fstream>
#include <iostream>
#include <fstream>

using namespace std;

ProbingSimulation::ProbingSimulation() {}

ProbingSimulation::ProbingSimulation(string inputFilename, int N, int interval, int M, int largestPrime)
:m_inputFile(inputFilename), m_totalAmount(N), m_interval(interval), m_hashSize(M), m_largestPrime(largestPrime) {
	
	randInts = new int[m_totalAmount];
	for(int i = 0; i < m_totalAmount; i++) {
		randInts[i] = NULL;
	}

	LinearHashTable = new HashTable<int>(1, m_hashSize);
	QuadraticHashTable = new HashTable<int>(2, m_hashSize);
	DoubleHashTable = new HashTable<int>(3, m_hashSize, m_largestPrime);

	//QuadraticHashTable = new HashTable<int>(m_hashSize);

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

	cout << "Linear Probing Analysis (Table size = " << m_hashSize << ")\n";
	int i = 0;
	HashTable<int> *FinalHashTable = LinearHashTable;
	while(randInts[i] != NULL) {
		LinearHashTable->incrementN();
		//cout << LinearHashTable->getCurrentN() << " Looking at " << randInts[i] << endl;
		LinearHashTable->insert(randInts[i]);
		i++;
		if (i % m_interval == 0)
			FinalHashTable->printStatistics();
	}
	
	
	cout << "Quadratic Probing Analysis (Table size = " << m_hashSize << ")\n";
	i = 0;
	while(randInts[i] != NULL) {
		//cout << "Looking at " << randInts[i] << endl;
		QuadraticHashTable->insert(randInts[i]);
		i++;
		if (i % m_interval == 0)
			QuadraticHashTable->printStatistics();
	}

	cout << "Doublehash Probing Analysis (Table size = " << m_hashSize << ")\n";
	i = 0;
	while (randInts[i] != NULL) {
		//cout << "Looking at " << randInts[i] << endl;
		DoubleHashTable->insert(randInts[i]);
		i++;
		if(i % m_interval == 0)
			DoubleHashTable->printStatistics();
	}

}