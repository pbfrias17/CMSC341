/*****************************************
** File:    ResultVehicle.h
** Project: Project 1
** Author:  Paolo Frias
** Date:    9/30/2014
** Section: 03
** E-mail:  pfrias2@umbc.edu

**   This file contains the ResultVehicle class definition
**It has all the methods and members
***********************************************/

#ifndef RESULTVEHICLE_H
#define RESULTVEHICLE_H

class ResultVehicle {
public:
	//---------------------------------------------------------
	// Name: ResultVehicle (default constructor)
	// PreCondition:  None
	// PostCondition: Creates an instance of ResultVehicle class 
	//---------------------------------------------------------
	ResultVehicle();

	//---------------------------------------------------------
	// Name: TrafficSim (alternative constructor)
	// PreCondition:  None
	// PostCondition: Creates an instance of ResultVehicle class 
	// with type(vehicle_type), timeSpent(time)
	//---------------------------------------------------------
	ResultVehicle(char vehicle_type, int time);

	//---------------------------------------------------------
	// Name: getType
	// PreCondition:  None
	// PostCondition: Returns type
	//---------------------------------------------------------
	char getType();

	//---------------------------------------------------------
	// Name: getTimeSpent
	// PreCondition:  None
	// PostCondition: Returns timeSpent 
	//---------------------------------------------------------
	int getTimeSpent();

	//---------------------------------------------------------
	// Name: setType
	// PreCondition:  None
	// PostCondition: Declares type(vehicle_type)
	//---------------------------------------------------------
	void setType(char vehicle_type);

	//---------------------------------------------------------
	// Name: setTimeSpent
	// PreCondition:  None
	// PostCondition: Declares timeSpent(time)
	//---------------------------------------------------------
	void setTimeSpent(int time);

private:
	int timeSpent;
	char type;
};



#endif //RESULTVEHICLE_H