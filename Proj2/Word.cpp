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


//Operation Overloading
bool operator< (const Word &lhs, const Word &rhs) {
	
	//only iterate through the shorter of the two words
	string lhsWord = lhs.getWordText();
	string rhsWord = rhs.getWordText();
	/*
	string shortWord;
	string longWord;
	if (lhsWord.size() < rhsWord.size()) {
		shortWord = lhsWord;
		longWord = rhsWord;
	} else {
		shortWord = rhsWord;
		longWord = lhsWord;
	}
	string::iterator s_iter = shortWord.begin();
	string::iterator l_iter = longWord.begin();

	/*
	for ( ; s_iter != shortWord.end(); s_iter++, l_iter++) {
		char s_ch = *s_iter;
		char l_ch = *l_iter;
		(if s_ch < )
	}
	*/
	if (lhsWord < rhsWord)
		//cout << lhsWord << " < " << rhsWord << endl;
		return true;
	else
		//cout << lhsWord << " > " << rhsWord << endl;
		return false;
}

/*
bool operator> (const Word &lhs, const Word &rhs) {
	return true;
}
*/

ostream& operator<<(ostream& os, const Word &rhs) {
	//But this should also print out word count and line numbers!
	queue<int> lines = rhs.getLineNumbers(); 
	os << rhs.getWordText() << "..." << rhs.getCount() << ": ";
	os << "Size of list = " << lines.size() << endl;
	for (int i = 0; i <= lines.size(); i++) {
		os << lines.front() << " ";
		lines.pop();
	}
	os << "\n";
	return os;
}