#ifndef INDEXER_H
#define INDEXER_H

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class Indexer {
public:
	Indexer();
	Indexer(string filter, string data);
	void DoIndex();

private:
	string filterFilename;
	string dataFilename;

};

#endif //INDEXER_H