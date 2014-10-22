/**
**File: Word.h
**Author: Paolo Frias
**Due Date: 10/21/14
**Section: 03
**
** Holds the class definition of the Word class
**which is the Comparable element we use in our
**generic BSTs
**/

#ifndef WORD_H
#define WORD_H
#include <string>
#include <queue>
using namespace std;

class Word {
public:

	/**
	**Word() - Default Constructor
	**Precondition: None
	**Postcondition: Creates a Word object
	**/
	Word();

	/**
	**Word() - Alternate Constructor
	**Precondition: None
	**Postcondition: Creates a Word object with 
	**wordText(word)
	**/
	Word(string word);
	
	/**
	**setType(type)
	**Precondition: None
	**Postcondition: Sets word type as wordType(type)
	**/
	void setType(const string &type);

	/**
	**getType()
	**Precondition: None
	**Postcondition: Returns wordType
	**/
	string getType() const;

	/**
	**getWordText()
	**Precondition: None
	**Postcondition: Returns wordText
	**/
	string getWordText() const;

	/**
	**getCount()
	**Precondition: None
	**Postcondition: Returns count
	**/
	int getCount() const;

	/**
	**setCurrLineNum(lineNum)
	**Precondition: None
	**Postcondition: Sets currLineNum as currLineNum(lineNum)
	**/
	void setCurrLineNum(const int &lineNum);

	/**
	**getCurrLineNum()
	**Precondition: None
	**Postcondition: Returns currLineNum
	**/
	int getCurrLineNum() const;

	/**
	**getLineNumbers()
	**Precondition: None
	**Postcondition: Returns queue getLineNumbers
	**/
	queue<int> getLineNumbers() const;

	/**
	**CountWord()
	**Precondition: None
	**Postcondition: Increments count and pushes currLineNum
	**into queue LineNumbers
	**/
	void CountWord();

	/**
	**operator<
	**Precondition: None
	**Postcondition: Overloads < operator to compare Word objects
	**/
	friend bool operator<(const Word &lhs, const Word &rhs);

	/**
	**operator<<
	**Precondition: None
	**Postcondition: Overloads << operator to allow standard
	**output printing of Word objects
	**/
	friend ostream& operator<<(ostream& os, const Word &rhs);

private:
	string wordType;
	string wordText;
	int count;
	int currLineNum;
	queue<int> lineNumbers;
};

#endif //WORD_H