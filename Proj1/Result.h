/*****************************************
** File:    Result.h
** Project: Project 1
** Author:  Paolo Frias
** Date:    9/30/2014
** Section: 03
** E-mail:  pfrias2@umbc.edu

**   This file contains the Result class definition
**It has all the methods and members
***********************************************/

#ifndef RESULT_H
#define RESULT_H
#include "ResultVehicle.h"


class Result {
private:
	ResultVehicle vehicle;
	Result* next;
public:
	//---------------------------------------------------------
	// Name: Result (default constructor)
	// PreCondition:  None
	// PostCondition: Creates an instance of Result class 
	//---------------------------------------------------------
	Result();

	//---------------------------------------------------------
	// Name: getVehicle
	// PreCondition:  None
	// PostCondition: Returns vehicle member
	//---------------------------------------------------------
	ResultVehicle getVehicle();

	//---------------------------------------------------------
	// Name: getNext
	// PreCondition:  None
	// PostCondition: Returns next member
	//---------------------------------------------------------
	Result* getNext();

	//---------------------------------------------------------
	// Name: setVehicle
	// PreCondition:  None
	// PostCondition: Declares vehicle(r_vehicle)
	//---------------------------------------------------------
	void setVehicle(ResultVehicle r_vehicle);

	//---------------------------------------------------------
	// Name: setNext
	// PreCondition:  None
	// PostCondition: declares next(nextPtr) 
	//---------------------------------------------------------
	void setNext(Result* nextPtr);
};


#endif //RESULT_H