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
				cout << wordList[i] << " is already in the '" << (char)first << "' tree.\n";
				//table[first - 97].printRoot();
				table[first - 97].getRoot().IncrementFrequency();
				//table[first - 97].printRoot();
			} else {
				cout << "Inserting " << wordList[i] << " into " << first - 97 << " tree\n";
				table[first - 97].insert(Node(wordList[i], 1));
			}
		}
	}

	file.close();
}

void HashedSplays::PrintHashCountResults() {
	cout << "\nPrinting out Hash count results... \n";
	for (int i = 0; i < m_trees; i++) {
		cout << "This tree starts with " << table[i].getRoot() << endl;
		cout << " and has " << table[i].getNodeCount() << " nodes\n";
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