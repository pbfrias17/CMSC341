/*****************************************
** File:    IntersectionFlowRate.h
** Project: Project 1
** Author:  Paolo Frias
** Date:    9/30/2014
** Section: 03
** E-mail:  pfrias2@umbc.edu

**   This file contains the IntersectionFlowRate class definition
**It has all the methods and members
***********************************************/

#ifndef INTERSECTIONFLOWRATE_H
#define INTERSECTIONFLOWRATE_H

class IntersectionFlowRate {
private:
	int eastFlowRateCars;
	int westFlowRateCars;
	int northFlowRateCars;
	int southFlowRateCars;
	int eastFlowRateTrucks;
	int westFlowRateTrucks;
	int northFlowRateTrucks;
	int southFlowRateTrucks;

public:
	//---------------------------------------------------------
	// Name: IntersectionFlowRate (default constructor)
	// PreCondition:  None
	// PostCondition: Creates an instance of IntersectionFlowRate
	// class 
	//---------------------------------------------------------
	IntersectionFlowRate();

	//---------------------------------------------------------
	// Name: IntersectionFlowRate (default constructor)
	// PreCondition:  None
	// PostCondition: Creates an instance of IntersectionFlowRate
	// class with eastCarRate(ecr), westCarRate(wcr), southCarRate(scr)
	// northCarRate(ncr), eastTruckRate(etr), westTruckRate(wtr), 
	// southTruckRate(str), northTruckRate(ntr)
	//---------------------------------------------------------
	IntersectionFlowRate(int ecr, int wcr, int scr, int ncr, int etr, int wtr, int str, int ntr);

	//---------------------------------------------------------
	// Name: getEastCarRate
	// PreCondition:  None
	// PostCondition: Returns eastCarRate member
	//---------------------------------------------------------
	int getEastCarRate();

	//---------------------------------------------------------
	// Name: getWestCarRate
	// PreCondition:  None
	// PostCondition: Returns westCarRate member
	//---------------------------------------------------------
	int getWestCarRate();

	//---------------------------------------------------------
	// Name: getNorthCarRate
	// PreCondition:  None
	// PostCondition: Returns northCarRate member
	//---------------------------------------------------------
	int getNorthCarRate();

	//---------------------------------------------------------
	// Name: getSouthCarRate
	// PreCondition:  None
	// PostCondition: Returns southCarRate member
	//---------------------------------------------------------
	int getSouthCarRate();

	//---------------------------------------------------------
	// Name: getEastTruckRate
	// PreCondition:  None
	// PostCondition: Returns eastTruckRate member
	//---------------------------------------------------------
	int getEastTruckRate();

	//---------------------------------------------------------
	// Name: getWestTruckRate
	// PreCondition:  None
	// PostCondition: Returns westTruckRate member
	//---------------------------------------------------------
	int getWestTruckRate();

	//---------------------------------------------------------
	// Name: getNorthTruckRate
	// PreCondition:  None
	// PostCondition: Returns northTruckRate member
	//---------------------------------------------------------
	int getNorthTruckRate();

	//---------------------------------------------------------
	// Name: getSouthTruckRate
	// PreCondition:  None
	// PostCondition: Returns southTruckRate member
	//---------------------------------------------------------
	int getSouthTruckRate();

	//---------------------------------------------------------
	// Name: setEastCarRate
	// PreCondition:  None
	// PostCondition: Declares eastCarRate(rate)
	//---------------------------------------------------------
	void setEastCarRate(int rate);

	//---------------------------------------------------------
	// Name: setWestCarRate
	// PreCondition:  None
	// PostCondition: Declares westCarRate(rate)
	//---------------------------------------------------------
	void setWestCarRate(int rate);

	//---------------------------------------------------------
	// Name: setNorthCarRate
	// PreCondition:  None
	// PostCondition: Declares northCarRate(rate)
	//---------------------------------------------------------
	void setNorthCarRate(int rate);

	//---------------------------------------------------------
	// Name: setSouthCarRate
	// PreCondition:  None
	// PostCondition: Declares southCarRate(rate)
	//---------------------------------------------------------
	void setSouthCarRate(int rate);

	//---------------------------------------------------------
	// Name: setEastTruckRate
	// PreCondition:  None
	// PostCondition: Declares eastTruckRate(rate)
	//---------------------------------------------------------
	void setEastTruckRate(int rate);

	//---------------------------------------------------------
	// Name: setWestTruckRate
	// PreCondition:  None
	// PostCondition: Declares westTruckRate(rate)
	//---------------------------------------------------------
	void setWestTruckRate(int rate);

	//---------------------------------------------------------
	// Name: setNorthTruckRate
	// PreCondition:  None
	// PostCondition: Declares northTruckRate(rate)
	//---------------------------------------------------------
	void setNorthTruckRate(int rate);

	//---------------------------------------------------------
	// Name: setSouthTruckRate
	// PreCondition:  None
	// PostCondition: Declares southTruckRate(rate)
	//---------------------------------------------------------
	void setSouthTruckRate(int rate);
};


#endif //INTERSECTIONFLOWRATE_H