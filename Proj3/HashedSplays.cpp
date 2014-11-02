#include "HashedSplays.h"
#include "Util.h"
#include <iostream>
#include <typeinfo>

HashedSplays::HashedSplays() {}

HashedSplays::HashedSplays(const int &size) 
: m_trees(size) {}

void HashedSplays::FileReader(const string &filename) {
	ifstream file;
	if(Util::FileExists(filename)) {
		cout << "Creating Splay Tree from file: " << filename << endl;
		vector<string> wordList;
		Util::extractWords(filename, wordList);
		for(int i = 0; i < wordList.size(); i++) {
			int first = tolower(wordList[i][0]);
			cout << "Inserting " << wordList[i] << " into " << wordList[i][0] << " tree\n";
			table[first - 97].insert(Node(wordList[i], 1));
		}
	}

	file.close();
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