#pragma once
#ifndef Car_h

#include<string>
#include<iostream>

class Car 
{
public:
	Car();
	~Car();
	void API();
	struct carData 
	{
		std::string vehicleName;
		int terrain = 0;
		double speed = 0.0;
		double tankLevel = 0.0;
	}myCar;
private:
	void SimulatorInput(carData*);
	void RunSimulator(carData*);
};
#endif //!Car_h