#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class Util {
public:
	Util();
	static string Lower(const string &word) {
		string lowered;
		for(unsigned int letter = 0; letter < word.size(); letter++) {
			lowered.push_back((char)tolower(word[letter]));
		}
		return lowered;
	}

	static bool FileExists(const string &filename) {
		ifstream file;
		file.open(filename.c_str(), ios_base::in);
		
		if(file.fail()) {
			cout << "Cannot open file: " << filename << endl;
			return false;
		}

		file.close();
		return true;
	}

	static void extractWords(const string &filename, vector<string> &wordList) {
		ifstream file;
		file.open(filename.c_str(), ios_base::in);

		string line;
		bool endOfLine = false;
		int lineCount = 0;
		while(!file.eof())
		{
			getline(file, line);
			endOfLine = false;
			
			//Check to see if the line is blank
			if(line.size() == 0) {
				endOfLine = true;
			}

			string fullWord;
			int index = 0;
			while(!endOfLine) {
				bool endOfWord = false;
				while(!endOfWord) {
					if(line[index] == ' ' || line[index] == '\0') {
						if(line[index] == '\0') {
							endOfLine = true;
						}
						endOfWord = true;
					} else {
						int charDec = tolower(line[index]);
						char lowered = (char)tolower(line[index]);
						if((charDec >= 97 && charDec <= 122) || charDec == 39 || charDec == 45) {
							fullWord.push_back(line[index]);
						}
					}
					index++;
				}
				if(stripEnds(fullWord)) {
					wordList.push_back(fullWord);
					fullWord.clear();
				}
			}
		}
		file.close();
	}

	static bool stripEnds(string &word) {
		//if string is empty, strip nothing and return false
		if(word.size() == 0)
			return false;

		//strip both sides until you hit a letter (on each side)
		if(tolower(word[0]) < 97 || tolower(word[0]) > 122) {
			word.erase(0, 1);
			return stripEnds(word);
		} else if(tolower(word[word.size() - 1]) < 97 || tolower(word[word.size() - 1]) > 122) {
			word = word.substr(0, word.size() - 1);
			return stripEnds(word);
		} else {
			return true;
		}
	}	


};

#endif //UTIL_H