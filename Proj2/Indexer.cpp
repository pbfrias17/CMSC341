#include "Indexer.h"

Indexer::Indexer()
: dataFile("data.txt"), filterFile("filter.txt") {}

Indexer::Indexer(string data, string filter) 
: dataFile(data), filterFile(filter) {}

void Indexer::DoIndex() {
	cout << "Filter file: " << filterFile << endl;
	cout << "Data file: " << dataFile << endl;
	int stopper;
	cin >> stopper;
}