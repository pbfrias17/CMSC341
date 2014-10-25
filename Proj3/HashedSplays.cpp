#include "HashedSplays.h"
#include <iostream>
#include <typeinfo>

HashedSplays::HashedSplays() {}

HashedSplays::HashedSplays(const int &size) 
: arraySize(size) {}

void HashedSplays::FileReader(const string &filename) {
	cout << "Creating Splay Tree from file: " << filename << endl;
}

void HashedSplays::PrintHashCountResults() {
	cout << "Printing out Hash count results... \n";
}


void HashedSplays::PrintTree(const int &index) {
	cout << "Printing tree of index " << index << endl;
}

void HashedSplays::PrintTree(const string &index) {
	cout << "Printing tree of index " << index << endl;
}

void HashedSplays::FindAll(const string &target) {
	cout << "Now finding all entries that start with '" << target << "': \n";
}