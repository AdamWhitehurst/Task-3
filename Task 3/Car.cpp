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
		double speed = 0.0;
		double tank_level = 0.0;
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

void Car::simulator_input(data_car* myCar)
{
	cout << "Name your car, speedster!" << endl;
	cin >> myCar->vehicle_name;
	cout << "How tough is the terrain?? (1: easy, 2: tough, 3: really hard) ";
	while (!(myCar->terrain == 1 || myCar->terrain == 2 || myCar->terrain == 3)) {
		try {
			cin >> myCar->terrain;
		}
		catch (exception e) {
			cout << "Invalid terrain!" << endl;
		}
		if (!(myCar->terrain == 1 || myCar->terrain == 2 || myCar->terrain == 3)) {
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
		myCar->speed = 0.3;
		break;
	case 2:
		myCar->speed = 0.6;
		break;
	case 3:
		myCar->speed = 0.8;
		break;
	}

	cout << "How much fuel do you have?? (1: 100%, 2. 80%, 3. 50%) ";
	input = 0;
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
		myCar->tank_level = 100.0;
		break;
	case 2:
		myCar->tank_level = 80.0;
		break;
	case 3:
		myCar->tank_level = 50.0;
		break;
	}
}

void Car::run_simulator(data_car* myCar)
{
	while (myCar->tank_level > .01) {
		cout << "New tank level: " << myCar->tank_level << endl;
		myCar->tank_level -= myCar->speed * myCar->terrain;
	}
}

int main() {
	Car car;
	return 0;
	
}