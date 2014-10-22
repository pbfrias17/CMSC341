#include "Indexer.h"
#include "BinarySearchTree.h"
#include "Word.h"

Indexer::Indexer()
: filterFilename("gsl.txt"), dataFilename("data.txt") {
	filteredBST = new BinarySearchTree<Word>();
	indexedBST = new BinarySearchTree<Word>();
}

Indexer::Indexer(string filter, string data) 
: filterFilename(filter), dataFilename(data) {
	filteredBST = new BinarySearchTree<Word>();
	indexedBST = new BinarySearchTree<Word>();
}

void Indexer::DoIndex() {
	//////
	int stopper;
	////////


	if (FileExists(filterFilename) && FileExists(dataFilename)) {
		*filteredBST = FileFilterReader<Word>(filterFilename);
		filteredBST->printTree();
		*indexedBST = FileWordReader<Word>(dataFilename);
		//cout << "Done inserting... now printing\n";
		indexedBST->printTree();
	} else {
		cout << "Problem with the given files.\nExiting...";
		exit(1);
	}

	delete filteredBST;
	filteredBST = NULL;
	delete indexedBST;
	indexedBST = NULL;
	cin >> stopper;
}

bool Indexer::FileExists(const string &filename) {
	ifstream dataFile;
	dataFile.open(filename.c_str(), ios_base::in);

	if (dataFile.fail()) {
		cout << "Failed to open file: " << filename << endl;
		cout << "...exiting" << endl;
		return false;
	}

	dataFile.close();
	return true;
}

void Indexer::RemovePunctuation(string &word) {
	int firstASCII = tolower(word[0]);
	while (firstASCII < 97 || firstASCII > 122) {
		//cout << "Take out " << (char)firstASCII << endl;
		word.erase(0, 1);
		firstASCII = tolower(word[0]);
	}

	int lastASCII = tolower(word[word.size() - 1]);
	while (lastASCII < 97 || lastASCII > 122) {
		//cout << (char)lastASCII << endl;
		word = word.substr(0, word.size() - 1);
		lastASCII = tolower(word[word.size() - 1]);
	}
}

template <typename Comparable> BinarySearchTree<Comparable> Indexer::FileFilterReader(string filename) {
	//cout << "Creating a BST of Filterwords from " << filename << endl;
	ifstream filterFile;

	filterFile.open(filename.c_str(), ios_base::in);

	string filterWord;
	while (filterFile >> filterWord) {
		//convert string word into Word object
		Word word = Word(filterWord);
		word.setType("filter");
		filteredBST->insert(word);
	}

	filterFile.close();
	return *filteredBST;
}



template <typename Comparable> BinarySearchTree<Comparable> Indexer::FileWordReader(string filename) {
	//cout << "\n\nCreating a BST of indexed words from " << filename << endl;
	ifstream dataFile;
	dataFile.open(filename.c_str(), ios_base::in);

	string line;
	bool endOfLine = false;
	int lineCount = 0;
	while(!dataFile.eof())
	{	
		lineCount++;
		getline(dataFile, line);
		bool endOfLine = false;

		//Check to see if the line is blank
		if (line.size() == 0) {
			//cout << "\nLINE IS EMPTY\n";
			endOfLine = true;
		}

		string fullWord;
		int index = 0;
		//cout << "1\n";
		while(!endOfLine) {
			bool endOfWord = false;
			while(!endOfWord) {
				char lowered = (char)tolower(line[index]);

				if(line[index] == ' ' || line[index] == '\0') {

					if (fullWord.size() > 1)
						RemovePunctuation(fullWord);

					//check to see if word should be filtered out
					Word word = Word(fullWord);
					word.setType("indexed");
					if (!filteredBST->contains(word) && fullWord.size() > 1) {
						word.setCurrLineNum(lineCount);
						indexedBST->insert(word);
					} 

					endOfWord = true;

					if (line[index] == '\0') {
						endOfLine = true;
						index = 0;
					}
				} else {
					fullWord.append(1, lowered);
				}
				index++;
			}
			fullWord.clear();
		}
	}
	dataFile.close();

	return *indexedBST;

}