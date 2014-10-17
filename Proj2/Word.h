#ifndef WORD_H
#define WORD_H
#include <string>
#include <queue>
using namespace std;

class Word {
public:
	Word();
	Word(string word);
	int getCount() const;
	string getWordString() const;
	friend bool operator< (const Word &lhs, const Word &rhs);
	friend bool operator> (const Word &lhs, const Word &rhs);
private:
	string wordString;
	int count;
	//queue<int> lineNumbers;
};

#endif //WORD_H