#include "IntersectionFlowRate.h"

IntersectionFlowRate::IntersectionFlowRate()
	:eastFlowRateCars(1), westFlowRateCars(1), southFlowRateCars(1), northFlowRateCars(1),
	eastFlowRateTrucks(1), westFlowRateTrucks(1), southFlowRateTrucks(1), northFlowRateTrucks(1) {}

IntersectionFlowRate::IntersectionFlowRate(int ecr, int wcr, int scr, int ncr, int etr, int wtr, int str, int ntr)
	: eastFlowRateCars(ecr), westFlowRateCars(wcr), southFlowRateCars(scr), northFlowRateCars(ncr),
	eastFlowRateTrucks(etr), westFlowRateTrucks(wtr), southFlowRateTrucks(str), northFlowRateTrucks(ntr) {}

int IntersectionFlowRate::getEastCarRate() {
	return eastFlowRateCars;
}

int IntersectionFlowRate::getWestCarRate() {
	return westFlowRateCars;
}

int IntersectionFlowRate::getSouthCarRate() {
	return southFlowRateCars;
}

int IntersectionFlowRate::getNorthCarRate() {
	return northFlowRateCars;
}

int IntersectionFlowRate::getEastTruckRate() {
	return eastFlowRateTrucks;
}

int IntersectionFlowRate::getWestTruckRate() {
	return westFlowRateTrucks;
}

int IntersectionFlowRate::getSouthTruckRate() {
	return southFlowRateTrucks;
}

int IntersectionFlowRate::getNorthTruckRate() {
	return northFlowRateTrucks;
}

void IntersectionFlowRate::setEastCarRate(int rate) {
	eastFlowRateCars = rate;
}

void IntersectionFlowRate::setWestCarRate(int rate) {
	westFlowRateCars = rate;
}

void IntersectionFlowRate::setSouthCarRate(int rate) {
	southFlowRateCars = rate;
}

void IntersectionFlowRate::setNorthCarRate(int rate) {
	northFlowRateCars = rate;
}

void IntersectionFlowRate::setEastTruckRate(int rate) {
	eastFlowRateTrucks = rate;
}

void IntersectionFlowRate::setWestTruckRate(int rate) {
	westFlowRateTrucks = rate;
}

void IntersectionFlowRate::setSouthTruckRate(int rate) {
	southFlowRateTrucks = rate;
}

void IntersectionFlowRate::setNorthTruckRate(int rate) {
	northFlowRateTrucks = rate;
}