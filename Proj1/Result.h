#ifndef RESULT_H
#define RESULT_H
#include "ResultVehicle.h"


class Result {
private:
	ResultVehicle vehicle;
	Result* next;
public:
	Result();
	ResultVehicle getVehicle();
	Result* getNext();
	void setVehicle(ResultVehicle r_vehicle);
	void setNext(Result* nextPtr);
};


#endif //RESULT_H