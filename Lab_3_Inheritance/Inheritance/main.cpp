#include "classes.hpp"

int main() {
	system("chcp1251");
	setlocale(0, "");
	system("cls");

	Car objCar;
	Bicycle objBicycle;
	Wagon objWagon;

	double distance = 500;
	double cargoWeight = 100;

	std::cout << "\n\tМашина: " << std::endl;
	/*std::cout << "\tВремя перевозки пассажира: " << objCar.calculatePassengerTime(distance) << " часов" << std::endl;
	std::cout << "\tСтоимость перевозки пассажира: " << objCar.calculatePassengerCost(distance) << " $" << std::endl;
	std::cout << "\tВремя перевозки груза: " << objCar.calculateCargoTime(distance, cargoWeight) << " часов" << std::endl;
	std::cout << "\tСтоимость перевозки груза: " << objCar.calculateCargoCost(distance, cargoWeight) << " $" << std::endl;*/
	printObjResults(objCar, distance, cargoWeight); 

	std::cout << "\n\tВелосипед: " << std::endl;
	/*std::cout << "\tВремя перевозки пассажира: " << objBicycle.calculatePassengerTime(distance) << " часов" << std::endl;
	std::cout << "\tСтоимость перевозки пассажира: " << objBicycle.calculatePassengerCost(distance) << " $" << std::endl;
	std::cout << "\tВремя перевозки груза: " << objBicycle.calculateCargoTime(distance, cargoWeight) << " часов" << std::endl;
	std::cout << "\tСтоимость перевозки груза: " << objBicycle.calculateCargoCost(distance, cargoWeight) << " $" << std::endl;*/
	printObjResults(objBicycle, distance, cargoWeight); 

	std::cout << "\n\tПавозка: " << std::endl;
	/*std::cout << "\tВремя перевозки пассажира: " << objWagon.calculatePassengerTime(distance) << " часов" << std::endl;
	std::cout << "\tСтоимость перевозки пассажира: " << objWagon.calculatePassengerCost(distance) << " $" << std::endl;
	std::cout << "\tВремя перевозки груза: " << objWagon.calculateCargoTime(distance, cargoWeight) << " часов" << std::endl;
	std::cout << "\tСтоимость перевозки груза: " << objWagon.calculateCargoCost(distance, cargoWeight) << " $" << std::endl;*/
	printObjResults(objWagon, distance, cargoWeight); 

	return 0;
}