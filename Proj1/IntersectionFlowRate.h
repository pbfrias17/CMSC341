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
	IntersectionFlowRate();
	IntersectionFlowRate(int ecr, int wcr, int scr, int ncr, int etr, int wtr, int str, int ntr);
	int getEastCarRate();
	int getWestCarRate();
	int getNorthCarRate();
	int getSouthCarRate();
	int getEastTruckRate();
	int getWestTruckRate();
	int getNorthTruckRate();
	int getSouthTruckRate();
	void setEastCarRate(int rate);
	void setWestCarRate(int rate);
	void setNorthCarRate(int rate);
	void setSouthCarRate(int rate);
	void setEastTruckRate(int rate);
	void setWestTruckRate(int rate);
	void setNorthTruckRate(int rate);
	void setSouthTruckRate(int rate);



};


#endif //INTERSECTIONFLOWRATE_H