#include "Vehicle.h"

Vehicle::Vehicle()
: type('c'), timeEntered(30) {}

Vehicle::Vehicle(char v_type, int time)
: type(v_type), timeEntered(time) {}

char Vehicle::getType() {
	return type;
}

int Vehicle::getTimeEntered() {
	return timeEntered;
}

void Vehicle::setType(char v_type) {
	type = v_type;
}

void Vehicle::setTimeEntered(int time) {
	timeEntered = time;
}