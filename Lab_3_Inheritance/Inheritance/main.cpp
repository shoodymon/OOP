#include "classes.hpp"

int main() {
	system("chcp1251");
	setlocale(0, "");
	system("cls");

	Car objCar(80, 5, 0.5);
	Bicycle objBicycle(15, 1, 0.1);
	Wagon objWagon(10, 2, 0.2);

	double distance = 500;
	double cargoWeight = 100;

	std::cout << "\n\tМашина: " << std::endl;
	printObjResults(objCar, distance, cargoWeight); 

	std::cout << "\n\tВелосипед: " << std::endl;
	printObjResults(objBicycle, distance, cargoWeight); 

	std::cout << "\n\tПавозка: " << std::endl;
	printObjResults(objWagon, distance, cargoWeight); 

	return 0;
}