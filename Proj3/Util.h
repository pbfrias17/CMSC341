#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <fstream>

using namespace std;

class Util {
public:
	Util();
	static string Lower(const string &word) {
		return word;
	}

	static bool FileExists(const string &filename) {
		ifstream file;
		file.open(filename.c_str(), ios_base::in);
		
		if(file.fail())
			return false;

		file.close();
		return true;
	}

	//add more methods


private:
	int randomLOL;

};

#endif //UTIL_H