#ifndef WORD_H
#define WORD_H
#include <string>
#include <queue>
using namespace std;

class Word {
public:
	Word();
	Word(string word);
	
	void setType(const string &type);
	string getType() const;
	string getWordText() const;
	int getCount() const;
	void setCurrLineNum(const int &lineNum);
	int getCurrLineNum() const;
	queue<int> getLineNumbers() const;
	void CountWord();
	friend bool operator<(const Word &lhs, const Word &rhs);
	friend ostream& operator<<(ostream& os, const Word &rhs);

private:
	string wordType;
	string wordText;
	int count;
	int currLineNum;
	queue<int> lineNumbers;
};

#endif //WORD_H