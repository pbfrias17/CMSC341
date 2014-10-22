/**
**File: Indexer.h
**Author: Paolo Frias
**Due Date: 10/21/14
**Section: 03
**
** Holds the class definition of the Indexer class
**which is the main interface for the indexing of
**a text file
**/

#ifndef INDEXER_H
#define INDEXER_H

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

#include "BinarySearchTree.h"
#include "Word.h"

using namespace std;

class Indexer {
public:
	/**
	**Indexer() - Default Constructor
	**Precondition: Files must be present
	**Postcondition: Creates an indexer object with 
	**filterFilename(gsl.txt), dataFilename(data.txt)
	**/
	Indexer();

	/**
	**Indexer(filter, data) - Alternate Constructor
	**Precondition: Files must be present
	**Postcondition: Creates an indexer object with
	**filterFilename(filter), dataFilename(data)
	**/
	Indexer(string filter, string data);

	/**
	**DoIndex()
	**Precondition: None
	**Postcondition: Reads in files and creates/prints 
	**BSTs of filterwords and indexed text
	**/
	void DoIndex();

private:
	string filterFilename;
	string dataFilename;
	BinarySearchTree<Word> *filteredBST;
	BinarySearchTree<Word> *indexedBST;

	/**
	**FileExists(filename)
	**Precondition: None
	**Postcondition: Checks to see if the given file exists
	**/
	bool FileExists(const string& filename);

	/**
	**RemovePunctuation(word)
	**Precondition: None
	**Postcondition: Removes non-alphanumeric characters from
	** beginning and end of provided word
	**/
	void RemovePunctuation(string &word);

	/**
	**FileFilterReader(filename)
	**Precondition: Filename must exist
	**Postcondition: Reads in filter file and creates a BST
	**of filter words
	**/
	template <typename Comparable> BinarySearchTree<Comparable> FileFilterReader(string filename);
	
	/**
	**FileWordReader(filename)
	**Precondition: Filename must exist
	**Postcondition: Reads in text file and filters the text. Then
	**indexes remaining words into another BST
	**/
	template <typename Comparable> BinarySearchTree<Comparable> FileWordReader(string filename);
	
	/**
	**OutputResutls()
	**Precondition: None
	**Postcondition: Removes non-alphanumeric characters from
	** beginning and end of provided word
	**/
	void OutputResults() const;


};

#endif //INDEXER_H