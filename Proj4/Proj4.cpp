#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include "ProbingSimulation.h"

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
	cout << "Done testing. Now Comparing results...\n";

	delete PS;
	PS = NULL;

	cin >> stopper;
	return 0;
}