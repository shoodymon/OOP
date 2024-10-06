#include "Classes.hpp"

int main() {
	setlocale(0, "");
	system("chcp1251");
	system("cls");

	B obj1("Mark", 12);
	D1 obj2("Steven", 15);
	D2 obj3("Travis", 64);
	D3 obj4("Hooch", 43, "George", 37);

	std::cout << "\n\tДемонстрация работы: " << std::endl;

	obj1.show();
	obj2.show();
	obj3.show();
	obj4.show();
}