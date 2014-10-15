/*****************************************
** File:    TrafficSim.h
** Project: Project 1
** Author:  Paolo Frias
** Date:    9/30/2014
** Section: 03
** E-mail:  pfrias2@umbc.edu

**   This file contains the TrafficSim class definition
**It has all the methods and members
***********************************************/

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
		string inputFile;

	public:
		//---------------------------------------------------------
		// Name: TrafficSim (default constructor)
		// PreCondition:  None
		// PostCondition: Creates an instance of TrafficSim class 
		//---------------------------------------------------------
		TrafficSim();

		//---------------------------------------------------------
		// Name: TrafficSim (alternative constructor)
		// PreCondition:  None
		// PostCondition: Creates an instance of TrafficSim class
		// with string filename
		//---------------------------------------------------------
		TrafficSim(string file);

		//---------------------------------------------------------
		// Name: DoRun
		// PreCondition:  None
		// PostCondition: Starts the simluation process
		//---------------------------------------------------------
		void DoRun();
};

#endif //TRAFFICSIM_H