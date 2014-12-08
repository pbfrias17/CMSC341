/**************************************************************
* File:     ProbingSimulation.cpp
* Project:  CMSC 341 - Project 4
* Author:   Paolo Frias
* Due Date: 18-November-2014
* Section:  Lecture-02
* E-mail:   pfrias2@umbc.edu
*
* ProbingSimulation class implementation
*************************************************************/

#include "ProbingSimulation.h"
#include <fstream>
#include <iostream>


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
}

ProbingSimulation::~ProbingSimulation() {
	delete[] randInts;
	randInts = NULL;

	delete LinearHashTable;
	LinearHashTable = NULL;

	delete QuadraticHashTable;
	QuadraticHashTable = NULL;

	delete DoubleHashTable;
	DoubleHashTable = NULL;
}

void ProbingSimulation::ReadInput() {

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

	cout << "Linear Probing Analysis(Table size = " << m_hashSize << ")\n";		
	cout << "             --- Inserts ---   ------- Probing -------    ----- Clusters ------\n";
	cout << "N   Lambda   Success  Failed     Total    Avg      Max    Amount    Avg     Max\n";
	int i = 0;
	HashTable<int> *FinalHashTable = LinearHashTable;
	while(randInts[i] != NULL) {
		LinearHashTable->incrementN();
		LinearHashTable->insert(randInts[i]);
		i++;
		if (i % m_interval == 0)
			FinalHashTable->printStatistics();
	}
	
	
	cout << "Quadratic Probing Analysis (Table size = " << m_hashSize << ")\n";
	cout << "             --- Inserts ---   ------- Probing -------    ----- Clusters ------\n";
	cout << "N   Lambda   Success  Failed    Total    Avg      Max    Amount    Avg     Max\n";
	i = 0;
	while(randInts[i] != NULL) {
		QuadraticHashTable->insert(randInts[i]);
		i++;
		if (i % m_interval == 0)
			QuadraticHashTable->printStatistics();
	}

	cout << "Doublehash Probing Analysis (Table size = " << m_hashSize << ")\n";
	cout << "             --- Inserts ---   ------- Probing -------    ----- Clusters ------\n";
	cout << "N   Lambda   Success  Failed     Total    Avg      Max    Amount    Avg     Max\n";
	i = 0;
	while (randInts[i] != NULL) {
		DoubleHashTable->insert(randInts[i]);
		i++;
		if(i % m_interval == 0)
			DoubleHashTable->printStatistics();
	}

}