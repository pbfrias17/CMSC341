#ifndef TRAFFICSIM_H
#define TRAFFICSIM_H

#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include "Vehicle.h"

using namespace std;

class TrafficSim {
	private:
		queue <Vehicle> northbound;
		queue <Vehicle> southbound;
		queue <Vehicle> eastbound;
		queue <Vehicle> westbound;
		int NSDuration;
		int EWDuration;
		string inputFile;
		int stopper; //DELETE WHEN DONE

	public:
		TrafficSim();
		TrafficSim(string file);
		int getNSDuration();
		int getEWDuration();
		void setNSDuration(int duration);
		void setEWDuration(int duration);
		bool NSGreen();
		void DoRun();




};

#endif //TRAFFICSIM_H