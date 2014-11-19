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

	int i = 0;
	
	/*while(randInts[i] != NULL && !LinearHashTable->isFull()) {
		cout << "Looking at " << randInts[i] << endl;
		LinearHashTable->insert(randInts[i]);
		i++;
	}

	i = 0;
	while(randInts[i] != NULL && !QuadraticHashTable->isFull()) {
		cout << "Looking at " << randInts[i] << endl;
		QuadraticHashTable->insert(randInts[i]);
		i++;
	}*/

	i = 0;
	while (randInts[i] != NULL && !DoubleHashTable->isFull()) {
		cout << "Looking at " << randInts[i] << endl;
		DoubleHashTable->insert(randInts[i]);
		i++;
	}


	

}