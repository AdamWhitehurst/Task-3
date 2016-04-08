#include "Car.h"

Car::Car()
{
	API();
}


Car::~Car()
{
}

void Car::API()
{
	SimulatorInput(&myCar);
	RunSimulator(&myCar);
}

void Car::SimulatorInput(carData* myCar)
{
	std::cout << "Name your car, speedster!\n";
	std::getline(std::cin, myCar->vehicleName);
	std::cout << "How tough is the terrain?? (1: easy, 2: tough, 3: really hard) ";
	while (!(myCar->terrain == 1 || myCar->terrain == 2 || myCar->terrain == 3)) {
		try {
			std::cin >> myCar->terrain;
		}
		catch (std::exception e) {
			std::cout << "Invalid terrain!\n";
		}
		if (!(myCar->terrain == 1 || myCar->terrain == 2 || myCar->terrain == 3)) {
			std::cout << "That's not an allowed terrain toughness, try another! ";
		}
	}

	std::cout << "How fast do you go?? (1: slow, 2: medium, 3: fast!)";
	int input = 0;
	while (!(input == 1 || input == 2 || input == 3)) {
		try {
			std::cin >> input;
		}
		catch (std::exception e) {
			std::cout << "Invalid speed!\n";
		}
		if (!(input == 1 || input == 2 || input == 3)) {
			std::cout << "That's not an allowed speed setting, try another! ";
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

	std::cout << "How much fuel do you have?? (1: 100%, 2. 80%, 3. 50%) ";
	input = 0;
	while (!(input == 1 || input == 2 || input == 3)) {
		try {
			std::cin >> input;
		}
		catch (std::exception e) {
			std::cout << "Invalid fuel amount!\n";
		}
		if (!(input == 1 || input == 2 || input == 3)) {
			std::cout << "That's not an allowed fuel amount, try another! ";
		}
	}
	switch (input) {
	case 1:
		myCar->tankLevel = 100.0;
		break;
	case 2:
		myCar->tankLevel = 80.0;
		break;
	case 3:
		myCar->tankLevel = 50.0;
		break;
	}
}

void Car::RunSimulator(carData* myCar)
{
	while (myCar->tankLevel > .01) {
		std::cout << "New tank level: " << myCar->tankLevel << "\n";
		myCar->tankLevel -= myCar->speed * myCar->terrain;
	}
	std::cout << "You're out of gas!\n";
}

int main() {
	Car car;
	return 0;
}