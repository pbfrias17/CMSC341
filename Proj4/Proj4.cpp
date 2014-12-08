/**************************************************************
* File:     Proj4.cpp
* Project:  CMSC 341 - Project 4
* Author:   Paolo Frias
* Due Date: 18-November-2014
* Section:  Lecture-02
* E-mail:   pfrias2@umbc.edu
*
* Driver for Proj4. Creates a ProbingSimulation object and runs
*through the probe testing
*************************************************************/

#include "ProbingSimulation.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>


using namespace std;

int main(int argc, char* argv[]) {

	char stopper;

	string inputFilename = argv[1];
	int N = atoi(argv[2]);
	const int INTERVAL = atoi(argv[3]);
	const int M = atoi(argv[4]);
	int largestPrime = atoi(argv[5]);

	ProbingSimulation* PS = new ProbingSimulation(inputFilename, N, INTERVAL, M, largestPrime); 

	PS->ReadInput();
	PS->RunTests();

	delete PS;
	PS = NULL;

	cin >> stopper;
	return 0;
}