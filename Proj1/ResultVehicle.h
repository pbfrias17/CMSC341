#ifndef RESULTVEHICLE_H
#define RESULTVEHICLE_H

class ResultVehicle {
public:
	ResultVehicle();
	ResultVehicle(char vehicle_type, int time);
	char getType();
	int getTimeSpent();
	void setType(char type);
	void setTimeSpent(int time);
private:
	int timeSpent;
	char type;
};



#endif //RESULTVEHICLE_H