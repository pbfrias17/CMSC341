#include "Result.h"
#include "ResultVehicle.h"
#include <iostream>

Result::Result()
	: next(0) {}

ResultVehicle Result::getVehicle() {
	return vehicle;
}

Result* Result::getNext() {
	return next;
}

void Result::setVehicle(ResultVehicle r_vehicle) {
	vehicle = r_vehicle;
	//setNext(new Result);
}

void Result::setNext(Result* nextPtr) {
	next = nextPtr;
}