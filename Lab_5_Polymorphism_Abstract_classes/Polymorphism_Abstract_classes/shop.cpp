#include "includes.hpp"
#include "shop.hpp"

void shop(Store& store, Cart& cart, Bank& bank) {
	std::cout << "����� ���������� � " << store.getName() << std::endl;

	for (const auto& department : store.getDepartments()) {
		department.display();
		for (const auto& item : department.getItems()) {
			char choice;
			std::cout << "�������� � ������� ? (y / n) : ";
			std::cin >> choice;
			if (choice == 'y' || choice == 'Y') {
				cart.addItem(item);
			}
		}
	}

	cart.display();

	if (bank.withdraw(cart.getTotal())) {
		std::cout << "������� �������!" << std::endl;
	} 
	else {
		std::cout << "������������ �������." << std::endl;
	}
}