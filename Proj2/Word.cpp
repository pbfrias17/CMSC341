#include "Word.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Word::Word()
	:wordText("HELLO!"), count(0) {}

Word::Word(string word)
	: wordText(word), count(0)  {}

void Word::setType(const string& type) {
	wordType = type;
}

string Word::getType() const {
	return wordType;
}

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
	//don't duplicate line numbers
	if (lineNumbers.size() == 0)
		lineNumbers.push(currLineNum);
	else if (lineNumbers.back() != currLineNum)
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
	//Each tree needs different printing layouts
	if (rhs.getType() == "indexed") {
		//But this should also print out word count and line numbers!
		queue<int> lines = rhs.getLineNumbers();
		//layout must be right-justified
		os << rhs.getWordText();
		for (int i = 1; i <= 22 - rhs.getWordText().size(); i++) {
			os << ".";
		}
		
		if (rhs.getCount() < 10)
			os << ".";
		
		os << rhs.getCount() << ": ";

		while (!lines.empty()) {
			os << lines.front() << " ";
			lines.pop();
		}
	} else {
		os << rhs.getWordText();
	}
	os << "\n";
	return os;
}