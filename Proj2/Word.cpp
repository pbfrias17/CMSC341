#include "Word.h"
#include <iostream>

using namespace std;

Word::Word()
	:wordString("HELLO!"), count(0) {}

Word::Word(string word)
	: wordString(word), count(0)  {}

int Word::getCount() const{
	return count;
}

string Word::getWordString() const{
	return wordString;
}


//Operation Overloading
bool operator< (const Word &lhs, const Word &rhs) {
	cout << "!!!!!!!!!!!!!!!!!!!" << endl;
	string lhsWord = lhs.getWordString();
	int stopper;
	for (string::iterator it = lhsWord.begin(); it != lhsWord.end(); ++it) {
		char ch = *it;
		cout << ch << endl;
		cin >> stopper;
	}
	return true;
}

bool operator> (const Word &lhs, const Word &rhs) {
	return true;
}