#include "Word.h"

Word::Word()
	:wordString("HELLO!"), count(0) {}

Word::Word(string word)
	: wordString(word), count(0)  {}

int Word::getCount() {
	return count;
}