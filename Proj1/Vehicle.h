/*****************************************
** File:    Vehicle.h
** Project: Project 1
** Author:  Paolo Frias
** Date:    9/30/2014
** Section: 03
** E-mail:  pfrias2@umbc.edu

**   This file contains the Vehicle class definition
**It has all the methods and members
***********************************************/

#ifndef VEHICLE_H
#define VEHICLE_H

class Vehicle {
private:
	char type;
	int timeEntered;

public:
	//---------------------------------------------------------
	// Name: Vehicle (default constructor)
	// PreCondition:  None
	// PostCondition: Creates an instance of Vehicle class 
	//---------------------------------------------------------
	Vehicle();

	//---------------------------------------------------------
	// Name: Vehicle (alternative constructor)
	// PreCondition:  None
	// PostCondition: Creates an instance of Vehicle class with
	// type(v_type), timeEntered(time)
	//---------------------------------------------------------
	Vehicle(char v_type, int time);

	//---------------------------------------------------------
	// Name: getType
	// PreCondition:  None
	// PostCondition: returns type member
	//---------------------------------------------------------
	char getType();

	//---------------------------------------------------------
	// Name: getTimeEntered
	// PreCondition:  None
	// PostCondition: returns timeEntered member 
	//---------------------------------------------------------
	int getTimeEntered();

	//---------------------------------------------------------
	// Name: setType
	// PreCondition:  None
	// PostCondition: Declares type(v_type)
	//---------------------------------------------------------
	void setType(char v_type);

	//---------------------------------------------------------
	// Name: setTimeEntered
	// PreCondition:  None
	// PostCondition: Declares timeEntered(time)
	//---------------------------------------------------------
	void setTimeEntered(int time);
};





#endif //VEHICLE_H
