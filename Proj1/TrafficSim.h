#ifndef TRAFFICSIM_H
#define TRAFFICSIM_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class TrafficSim {
	private:
		string inputFile;
		int stopper; //DELETE WHEN DONE

	public:
		TrafficSim();
		TrafficSim(string file);
		bool NSGreen();
		void DoRun();




};

#endif //TRAFFICSIM_H