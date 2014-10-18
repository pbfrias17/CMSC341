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
	//infile.open(inputFile.c_str(), ios_base::in);

	
	/*
	

	if(dataFile.fail()) {
		cout << "Failed to open file: " << dataFilename << endl;
		cout << "...exiting" << endl;
		cin >> stopper;
		exit(1);
	}

	while(dataFile >> word) {
		cout << word << endl;
	}
	*/


	BinarySearchTree<Word> filteredBST = FileFilterReader<Word>(filterFilename);
	BinarySearchTree<Word> indexedBST = FileWordReader<Word>(dataFilename);
	//filteredBST.printTree();


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

	BinarySearchTree<Word>* filteredBST = new BinarySearchTree<Word>();

	string filterWord;
	while (filterFile >> filterWord) {
		cout << "Look at: " << filterWord << endl;
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

	string line;
	string word;
	bool endOfLine = false;
	int lineCount = 0;
	while(!dataFile.eof())
	{	
		//Must keep track of current line number
		lineCount++;
		cout << "Line " << lineCount << ":\n";
		getline(dataFile, line);
		
		string fullWord;
		bool endOfLine = false;
		int index = 0;
		while(!endOfLine) {
			bool endOfWord = false;
			while(!endOfWord) {
				//Check to see if character is not alphanumeric
				fullWord.append(1, line[index]);
				index++;
				if(line[index] == ' ' || line[index] == '\0') {
					cout << "\tSPACE detected: word = " << fullWord << endl;
					endOfWord = true;
					fullWord.clear();
				}
			}
			if(line[index] == '\0') {
				cout << "\tNULL detected: finished parsing line\n";
				endOfLine = true;
				index = 0;
			}
		}
	}


	dataFile.close();
}