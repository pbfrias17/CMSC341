#include "Indexer.h"
#include "BinarySearchTree.h"

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
	ifstream filterFile;
	ifstream dataFile;
	filterFile.open(filterFilename.c_str(), ios_base::in);
	dataFile.open(dataFilename.c_str(), ios_base::in);
	string word;
	//infile.open(inputFile.c_str(), ios_base::in);

	/*
	if(filterFile.fail()) {
		cout << "Failed to open file: " << filterFilename << endl;
		cout << "...exiting" << endl;
		cin >> stopper;
		exit(1);
	}

	while(filterFile >> word) {
		cout << word << endl;
	}
	

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






	filterFile.close();
	dataFile.close();

	cin >> stopper;
}


BinarySearchTree<Comparable> Indexer::FileFilterReader(string filename) {
	cout << "Creating a BST of Filterwords from " << filename << endl;
	return BinarySearchTree<Comparable>();
}