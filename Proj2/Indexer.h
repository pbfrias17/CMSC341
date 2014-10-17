#ifndef INDEXER_H
#define INDEXER_H

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

#include "BinarySearchTree.h"

using namespace std;

class Indexer {
public:
	Indexer();
	Indexer(string filter, string data);
	void DoIndex();


private:
	string filterFilename;
	string dataFilename;
	bool FileExists(const string& filename);
	BinarySearchTree<Comparable> FileFilterReader(string filename);
	//BinarySearchTree FileWordReader(string filename);
	void OutputResults();


};

#endif //INDEXER_H