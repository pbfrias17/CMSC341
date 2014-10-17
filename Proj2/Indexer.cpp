#include "Indexer.h"
#include "BinarySearchTree.h"
#include "Word.h"

Indexer::Indexer()
: filterFilename("gsl.txt"), dataFilename("data.txt") {}

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


	dataFile.close();

	cin >> stopper;
}


template <typename Comparable> BinarySearchTree<Comparable> Indexer::FileFilterReader(string filename) {
	cout << "Creating a BST of Filterwords from " << filename << endl;
	ifstream filterFile;

	filterFile.open(filterFilename.c_str(), ios_base::in);

	if (filterFile.fail()) {
		cout << "Failed to open file: " << filterFilename << endl;
		cout << "...exiting" << endl;
		exit(1);
	}

	BinarySearchTree<Word>* filteredBST = new BinarySearchTree<Word>();

	string word;
	while (filterFile >> word) {
		cout << "Look at: " << word << endl;
		//convert string word into Word object
		Word word = Word(word);
		filteredBST->insert(word);
	}

	filterFile.close();

	return BinarySearchTree<Word>();
}