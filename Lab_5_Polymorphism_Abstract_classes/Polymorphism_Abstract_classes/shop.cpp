#include "includes.hpp"
#include "shop.hpp"

void shop(Store& store, Cart& cart, Bank& bank) {
	std::cout << "Добро пожаловать в " << store.getName() << std::endl;

	for (const auto& department : store.getDepartments()) {
		department.display();
		for (const auto& item : department.getItems()) {
			char choice;
			std::cout << "Добавить в корзину ? (y / n) : ";
			std::cin >> choice;
			if (choice == 'y' || choice == 'Y') {
				cart.addItem(item);
			}
		}
	}

	cart.display();

	if (bank.withdraw(cart.getTotal())) {
		std::cout << "Покупка удалась!" << std::endl;
	} 
	else {
		std::cout << "Недостаточно средств." << std::endl;
	}
}