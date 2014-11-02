#ifndef HASHEDSPLAYS_H
#define HASHEDSPLAYS_H

#include "SplayTree.h"
#include "Node.h"

#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

const int ALPHABET_SIZE = 26;

class HashedSplays {
public:
	HashedSplays();
	HashedSplays(const int &size);

	void FileReader(const string &filename);
	void PrintHashCountResults();

	//Should also be able to take in int value or letter - must be generic
	void PrintTree(const int &index);
	void PrintTree(const string &index);
	
	void FindAll(const string &target);



private:
	const int m_trees;
	//vector<SplayTree<Node> > table;
	vector<string> wordsList;
	array<SplayTree<Node>, 26> table;

	
};

#endif //HASHEDSPLAYS_H