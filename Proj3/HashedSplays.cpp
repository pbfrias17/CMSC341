/**************************************************************
* File:    HashedSplays.cpp
* Project: CMSC 341 - Project 3 - Word Frequency
* Author : Paolo B. Frias
* Date   : 04-November-2014
* Section: Lecture-02
* E-mail:
*
* Node Class implementation.
*************************************************************/

#include "HashedSplays.h"
#include "Util.h"
#include <iostream>
#include <typeinfo>

HashedSplays::HashedSplays()
	: m_trees(ALPHABET_SIZE) {}

HashedSplays::HashedSplays(const int &size)
	: m_trees(size) {}

void HashedSplays::FileReader(const string &filename) {
	ifstream file;
	if (Util::FileExists(filename)) {
		cout << "Creating Splay Tree from file: " << filename << endl;
		vector<string> wordList;
		Util::extractWords(filename, wordList);
		for (unsigned int i = 0; i < wordList.size(); i++) {
			int first = tolower(wordList[i][0]);
			if (table[first - 97].contains(Node(wordList[i], 1))) {
				table[first - 97].getRoot().IncrementFrequency();
			} else {
				table[first - 97].insert(Node(wordList[i], 1));
			}
		}
	}

	file.close();
}

void HashedSplays::PrintHashCountResults() {
	cout << "\nPrinting out Hash count results... \n";
	for (int i = 0; i < m_trees; i++) {
		if(table[i].isEmpty()) {
			cout << "Empty Tree" << endl;
		} else {
			cout << "This tree starts with " << table[i].getRoot() << " and has " << table[i].getNodeCount() << " nodes\n";
		}
	}

}


void HashedSplays::PrintTree(const int &index) {
	cout << "\nPrinting tree of index " << index << endl;
	table[index].printTree();
}

void HashedSplays::PrintTree(const string &index) {
	cout << "\nPrinting tree of index " << index << endl;
	table[tolower(index[0]) - 97].printTree();
}

void HashedSplays::FindAll(const string &target) {
	cout << "\nNow finding all entries that start with '" << target << "': \n";
	Node targetNode = Node(Util::Lower(target), 1);
	SplayTree<Node> searchTable = table[tolower(target[0]) - 97];
	searchTable.printMatches(targetNode);

}