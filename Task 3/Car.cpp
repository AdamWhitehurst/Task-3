#include<string>
#include<iostream>
using namespace std;

class Car {
public:
	Car();
	~Car();
	void API();
	struct data_car {
		string vehicle_name = "";
		int terrain = 0;
		float speed = 0.0;
		float tank_level = 0.0;
	}myCar;
private:
	void simulator_input(data_car*);
	void run_simulator(data_car*);
};


Car::Car()
{
	API();
}


Car::~Car()
{
}

void Car::API()
{
	simulator_input(&myCar);
	run_simulator(&myCar);
}

void Car::simulator_input(data_car* car)
{
	cout << "Name your car, speedster!" << endl;
	cin >> car->vehicle_name;
	cout << "How tough is the terrain?? (1: easy, 2: tough, 3: really hard) ";
	while (!(car->terrain == 1 || car->terrain == 2 || car->terrain == 3)) {
		try {
			cin >> car->terrain;
		}
		catch (exception e) {
			cout << "Invalid terrain!" << endl;
		}
		if (!(car->terrain == 1 || car->terrain == 2 || car->terrain == 3)) {
			cout << "That's not an allowed terrain toughness, try another! ";
		}
	}

	cout << "How fast do you go?? (1: slow, 2: medium, 3: fast!)";
	int input = 0;
	while (!(input == 1 || input == 2 || input == 3)) {
		try {
			cin >> input;
		}
		catch (exception e) {
			cout << "Invalid speed!" << endl;
		}
		if (!(input == 1 || input == 2 || input == 3)) {
			cout << "That's not an allowed speed setting, try another! ";
		}
	}
	switch (input) {
	case 1:
		car->speed = 0.3;
		break;
	case 2:
		car->speed = 0.6;
		break;
	case 3:
		car->speed = 0.8;
		break;
	}

	cout << "How much fuel do you have?? (1: 100%, 2. 80%, 3. 50%) ";
	int input = 0;
	while (!(input == 1 || input == 2 || input == 3)) {
		try {
			cin >> input;
		}
		catch (exception e) {
			cout << "Invalid fuel amount!" << endl;
		}
		if (!(input == 1 || input == 2 || input == 3)) {
			cout << "That's not an allowed fuel amount, try another! ";
		}
	}
	switch (input) {
	case 1:
		car->tank_level = 100.0;
		break;
	case 2:
		car->tank_level = 80.0;
		break;
	case 3:
		car->tank_level = 50.0;
		break;
	}
}

void Car::run_simulator(data_car* car)
{
	// *(car->tank_level) -= car->speed * car->terrain;
	// if (tank_level < .01)
}

int main() {
	Car car;
	return 0;
}