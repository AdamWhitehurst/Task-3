#include<string>
using namespace std;

class Car {
public:
	Car();
	~Car();
	void API();
private:
	void simulator_input();
	void run_simulator();

	struct data_car {
		string vehicle_name;
		float* terrain;
		float* speed;
		float* tank_level;
	}myCar;
};


Car::Car()
{
}


Car::~Car()
{
}

void Car::API()
{
}

void Car::simulator_input()
{
}

void Car::run_simulator()
{
	*(myCar.tank_level) -= myCar.speed * myCar.terrain;
	// if (tank_level < .01)
}
