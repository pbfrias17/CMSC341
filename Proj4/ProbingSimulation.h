/**************************************************************
* File:     ProbingSimulation.h
* Project:  CMSC 341 - Project 4
* Author:   Paolo Frias
* Due Date: 18-November-2014
* Section:  Lecture-02
* E-mail:   pfrias2@umbc.edu
*
* ProbingSimulation class definition
*************************************************************/

#ifndef PROBINGSIMLUATION_H
#define PROBINGSIMLUATION_H

#include "Probing.h"
#include <string>
#include <cstdlib>

using namespace std;

class ProbingSimulation {
public:
	/**********************************************************************
	* Name: ProbingSimulation (Default Constructor)
	* PreCondition: None
	*
	* PostCondition: Creates ProbingSimulation object with default values
	*********************************************************************/
	ProbingSimulation();

	/**********************************************************************
	* Name: ProbingSimulation (Alternate Constructor)
	* PreCondition: None
	*
	* PostCondition:  Creates ProbingSimulation object with given values
	*and necessary data structures
	*********************************************************************/
	ProbingSimulation(string inputFilename, int N, int interval, int M, int largestPrime);

	/**********************************************************************
	* Name: ~ProbingSimulation (Destructor)
	* PreCondition: None
	*
	* PostCondition: Delete memory allocated for object and data structures
	*********************************************************************/
	~ProbingSimulation();

	/**********************************************************************
	* Name: ReadInput
	* PreCondition: None
	*
	* PostCondition: Creates an array of integers read from the file given
	*in the command line
	*********************************************************************/
	void ReadInput();

	/**********************************************************************
	* Name: RunTests
	* PreCondition: None
	*
	* PostCondition: Fills the provided hashtables with various probing
	*methods and analyzes the results
	*********************************************************************/
	void RunTests();

private:

	HashTable<int> *LinearHashTable;
	HashTable<int> *QuadraticHashTable;
	HashTable<int> *DoubleHashTable;

	int* randInts;
	string m_inputFile;
	int m_totalAmount;
	int m_interval;
	int m_hashSize;
	int m_largestPrime;

};


#endif