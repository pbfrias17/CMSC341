#ifndef VEHICLE_H
#define VEHICLE_H

class Vehicle {
private:
	char type;
	int timeEntered;

public:
	Vehicle();
	Vehicle(char type, int time);
	char getType();
	int getTimeEntered();
	void setType(char type);
	void setTimeEntered(int time);
};





#endif //VEHICLE_H
