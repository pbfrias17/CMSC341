#include "Indexer.h"
#include "BinarySearchTree.h"
#include "Word.h"

Indexer::Indexer()
: filterFilename("gsl.txt"), dataFilename("data.txt") {
}

Indexer::Indexer(string filter, string data) 
: filterFilename(filter), dataFilename(data) {}

void Indexer::DoIndex() {
	//////
	int stopper;
	////////
	cout << "Filter file: " << filterFilename << endl;
	cout << "Data file: " << dataFilename << endl;

	//This should all be in filterFileReader methods
	ifstream dataFile;
	dataFile.open(dataFilename.c_str(), ios_base::in);
	string word;

	//These should be private members!
	BinarySearchTree<Word> filteredBST = FileFilterReader<Word>(filterFilename);
	filteredBST.printTree();
	BinarySearchTree<Word> indexedBST = FileWordReader<Word>(dataFilename);
	indexedBST.printTree();


	dataFile.close();

	cin >> stopper;
}


template <typename Comparable> BinarySearchTree<Comparable> Indexer::FileFilterReader(string filename) {
	cout << "Creating a BST of Filterwords from " << filename << endl;
	ifstream filterFile;

	filterFile.open(filename.c_str(), ios_base::in);

	if (filterFile.fail()) {
		cout << "Failed to open file: " << filename << endl;
		cout << "...exiting" << endl;
		exit(1);
	}

	//This should be a member
	BinarySearchTree<Word>* filteredBST = new BinarySearchTree<Word>();

	string filterWord;
	while (filterFile >> filterWord) {
		//convert string word into Word object
		Word word = Word(filterWord);
		filteredBST->insert(word);
	}
	filterFile.close();

	return *filteredBST;
}



template <typename Comparable> BinarySearchTree<Comparable> Indexer::FileWordReader(string filename) {
	cout << "\n\nCreating a BST of indexed words from " << filename << endl;
	ifstream dataFile;
	dataFile.open(filename.c_str(), ios_base::in);

	if(dataFile.fail()) {
		cout << "Failed to open file: " << filename << endl;
		cout << "...exiting" << endl;
		exit(1);
	}

	//This should be a member
	BinarySearchTree<Word>* indexedBST = new BinarySearchTree<Word>();

	string line;
	bool endOfLine = false;
	int lineCount = 0;
	while(!dataFile.eof())
	{	
		lineCount++;
		getline(dataFile, line);
		bool endOfLine = false;

		//Check to see if the line is blank
		if (line.size() == 0)
			endOfLine = true;

		string fullWord;
		int index = 0;
		
		while(!endOfLine) {
			bool endOfWord = false;
			while(!endOfWord) {
				char lowered = putchar(tolower(line[index]));
				
				if(line[index] == ' ' || line[index] == '\0') {
					int firstASCII = tolower(fullWord[0]);
					int lastASCII = tolower(fullWord[fullWord.size() - 1]);
					if (firstASCII < 97 || firstASCII > 122)
						fullWord.erase(0, 1);
					if (lastASCII < 97 || lastASCII > 122) {
						fullWord = fullWord.substr(0, fullWord.size() - 1);
					}
					indexedBST->insert(fullWord);
					endOfWord = true;
					if (line[index] == '\0') {
						endOfLine = true;
						index = 0;
					}
				} else {
					fullWord.append(1, lowered);
					cout << "\tAppended " << lowered << " to " << fullWord << endl;
				}
				index++;
			}
			fullWord.clear();
		}
	}
	dataFile.close();

	return *indexedBST;

}