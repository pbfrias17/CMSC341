#ifndef HASHEDSPLAYS_H
#define HASHEDSPLAYS_H

#include <iostream>
#include <string>

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
	int arraySize;
};

#endif //HASHEDSPLAYS_H