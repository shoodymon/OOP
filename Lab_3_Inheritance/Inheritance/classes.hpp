#pragma once

#include <iostream>

class Vehicle {
protected:
	double m_speed;
	double m_capacity;
	double m_cost_km;

public:
	Vehicle(double sp = 0, double cap = 0, double ct = 0) :
		m_speed(sp), m_capacity(cap), m_cost_km(ct) 
	{}

	virtual double calculatePassengerTime(double distance) {
		return distance / m_speed;
	}

	virtual double calculatePassengerCost(double distance) {
		return distance * m_cost_km;
	}

	virtual double calculateCargoTime(double distance, double cargoWeight) {
		double coefExtraTime = cargoWeight / 100;
		return distance / m_speed + coefExtraTime;
	}

	virtual double calculateCargoCost(double distance, double cargoWeight) {
		double coefExtraCost = cargoWeight * 0.1;
		return distance * m_cost_km + coefExtraCost;
	}
};

class Car : public Vehicle {
public:
	Car() : Vehicle(80, 5, 0.5) {}
	Car(double speed, double capacity, double cost_km) : Vehicle(speed, capacity, cost_km) {}
};

class Bicycle : public Vehicle {
public:
	Bicycle() : Vehicle(15, 1, 0.1) {}
	Bicycle(double speed, double capacity, double cost_km) : Vehicle(speed, capacity, cost_km) {}

	double calculateCargoTime(double distance, double cargoWeight) {
		double coefExtraTime = cargoWeight / 20;
		return distance / m_speed + coefExtraTime;
	}

	double calculateCargoCost(double distance, double cargoWeight) {
		double coefExtraCost = cargoWeight * 0.05;
		return distance * m_cost_km + coefExtraCost;
	}
};

class Wagon : public Vehicle {
public:
	Wagon() : Vehicle(10, 2, 0.2) {}
	Wagon(double speed, double capacity, double cost_km) : Vehicle(speed, capacity, cost_km) {}

	double calculateCargoTime(double distance, double cargoWeight) {
		double coefExtraTime = cargoWeight / 50;
		return distance / m_speed + coefExtraTime;
	}

	double calculateCargoCost(double distance, double cargoWeight) {
		double coefExtraCost = cargoWeight * 0.1;
		return distance * m_cost_km + coefExtraCost;
	}
};

void printObjResults(Vehicle& vehicle, double distance, double cargoWeight) {
	std::cout << "\tВремя перевозки пассажира: " << vehicle.calculatePassengerTime(distance) << " часов" << std::endl;
	std::cout << "\tСтоимость перевозки пассажира: " << vehicle.calculatePassengerCost(distance) << " $" << std::endl;
	std::cout << "\tВремя перевозки груза: " << vehicle.calculateCargoTime(distance, cargoWeight) << " часов" << std::endl;
	std::cout << "\tСтоимость перевозки груза: " << vehicle.calculateCargoCost(distance, cargoWeight) << " $" << std::endl;
}