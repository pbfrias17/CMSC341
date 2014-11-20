#ifndef PROBINGSIMLUATION_H
#define PROBINGSIMLUATION_H

#include "Probing.h"
#include <string>
#include <cstdlib>

using namespace std;

class ProbingSimulation {
public:
	ProbingSimulation();
	ProbingSimulation(string inputFilename, int N, int interval, int M, int largestPrime);
	~ProbingSimulation();
	void ReadInput();
	void RunTests();

private:
	//HashTable LinearHashTable;
	HashTable<int> *LinearHashTable;
	HashTable<int> *QuadraticHashTable;
	HashTable<int> *DoubleHashTable;

	//HashTable DoubleHashTable;

	int* randInts;
	string m_inputFile;
	int m_totalAmount;
	int m_interval;
	int m_hashSize;
	int m_largestPrime;

};


#endif