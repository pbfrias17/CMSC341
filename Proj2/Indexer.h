#ifndef INDEXER_H
#define INDEXER_H

#include <string>
#include <iostream>
using namespace std;

class Indexer {
public:
	Indexer();
	Indexer(string filter, string data);
	void DoIndex();

private:
	string filterFile;
	string dataFile;

};

#endif //INDEXER_H