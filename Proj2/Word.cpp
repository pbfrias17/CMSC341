#include "Word.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Word::Word()
	:wordText("HELLO!"), count(0) {}

Word::Word(string word)
	: wordText(word), count(0)  {}

string Word::getWordText() const{
	return wordText;
}

int Word::getCount() const{
	return count;
}

queue<int> Word::getLineNumbers() const {
	return lineNumbers;
}

void Word::CountWord() {
	lineNumbers.push(currLineNum);
	count++;
}

void Word::setCurrLineNum(const int &lineNum){
	currLineNum = lineNum;
}

int Word::getCurrLineNum() const{
	return currLineNum;
}


//Operation Overloading
bool operator< (const Word &lhs, const Word &rhs) {
	
	//only iterate through the shorter of the two words
	string lhsWord = lhs.getWordText();
	string rhsWord = rhs.getWordText();

	if (lhsWord < rhsWord)
		return true;
	else
		return false;
}

ostream& operator<<(ostream& os, const Word &rhs) {
	//But this should also print out word count and line numbers!
	queue<int> lines = rhs.getLineNumbers(); 
	os << rhs.getWordText() << "..." << rhs.getCount() << ": ";

	while (!lines.empty()) {
		os << lines.front() << " ";
		lines.pop();
	}
	os << "\n";
	return os;
}