#ifndef PROBINGSIMLUATION_H
#define PROBINGSIMLUATION_H

#include "HashTable.h"
#include <string>
#include <cstdlib>

using namespace std;

class ProbingSimulation {
public:
	ProbingSimulation();
	ProbingSimulation(string inputFilename, int N, int interval, int M);
	~ProbingSimulation();
	void ReadInput();
	void RunTests();

private:
	HashTable LinearHashTable;
	HashTable QuadraticHashTable;
	HashTable DoubleHashTable;

	int* randInts;
	string m_inputFile;
	int m_totalAmount;
	int m_interval;
	int m_hashSize; 

};


#endif