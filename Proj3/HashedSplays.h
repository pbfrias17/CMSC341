/**************************************************************
* File:    HashedSplays.h
* Project: CMSC 341 - Project 3 - Word Frequency
* Author : Paolo B. Frias
* Date   : 05-November-2014
* Section: Lecture-02
* E-mail:
*
* HashedSplays Class Definition.
*************************************************************/

#ifndef HASHEDSPLAYS_H
#define HASHEDSPLAYS_H

#include "SplayTree.h"
#include "Node.h"

#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

const int ALPHABET_SIZE = 26;

class HashedSplays {
public:

	/**********************************************************************
	* Name: HashedSplays - default constructor
	* PreCondition: None
	*
	* PostCondition: Creates an instance of the HashedSplays class
	*********************************************************************/
	HashedSplays();

	/**********************************************************************
	* Name: Lower
	* PreCondition: None
	*
	* PostCondition: Creates an instance of the HashedSplays class with
	*   m_trees(size)
	*********************************************************************/
	HashedSplays(const int &size);

	/**********************************************************************
	* Name: FileReader
	* PreCondition: None
	*
    * PostCondition: Reads in the given text file and compiles a splayTree 
	*   of xtracted words in the respective index of the table
	*********************************************************************/
	void FileReader(const string &filename);

	/**********************************************************************
	* Name: PrintHachCountResults
	* PreCondition: None
	*
	* PostCondition: Prints out the root of each SplayTree in the table
	*   and the amount of nodes in each
	*********************************************************************/
	void PrintHashCountResults();

	/**********************************************************************
	* Name: PrintTree - overloaded int
	* PreCondition: None
	*
	* PostCondition: Prints out the tree of the provided index (inorder)
	*********************************************************************/
	void PrintTree(const int &index);

	/**********************************************************************
	* Name: PrintTree - overloaded string
	* PreCondition: None
	*
	* PostCondition: Prints out the tree of the provided index (inorder)
	*********************************************************************/
	void PrintTree(const string &index);

	/**********************************************************************
	* Name: FindAll
	* PreCondition: None
	*
	* PostCondition: Searches through a SplayTable for the provided target
	*   and prints out the result
	*********************************************************************/
	void FindAll(const string &target);



private:
	const int m_trees;
	//vector<SplayTree<Node> > table;
	vector<string> wordsList;
	array<SplayTree<Node>, 26> table;

	
};

#endif //HASHEDSPLAYS_H