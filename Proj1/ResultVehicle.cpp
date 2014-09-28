#include "ResultVehicle.h"

ResultVehicle::ResultVehicle()
	:type('c'), timeSpent(1) {}

ResultVehicle::ResultVehicle(char vehicle_type, int time)
	: type(vehicle_type), timeSpent(time) {}

char ResultVehicle::getType() {
	return type;
}

int ResultVehicle::getTimeSpent() {
	return timeSpent;
}

void ResultVehicle::setType(char vehicle_type) {
	type = vehicle_type;
}

void ResultVehicle::setTimeSpent(int time) {
	timeSpent = time;
}