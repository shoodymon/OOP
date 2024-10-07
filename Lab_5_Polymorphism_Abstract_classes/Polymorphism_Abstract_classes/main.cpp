#include "includes.hpp"
#include "Items.hpp"
#include "StoreComponents.hpp"
#include "Bank.hpp"
#include "shop.hpp"

int main() {
	setlocale(0, "");
	system("chcp1251");
	system("cls");

	auto laptop = std::make_shared<Product>("�������", "TechCo", 999.99);
	auto smartphone = std::make_shared<Product>("��������", "PhoneCo", 599.99);
	auto repair = std::make_shared<Service>("�������� �������", 79.99, 60);

	Department electronics("�����������");
	electronics.addItem(laptop);
	electronics.addItem(smartphone);
	electronics.addItem(repair);

	Store myStore("MyStore", "������� �����������");
	myStore.addDepartment(electronics);

	Cart myCart;
	Bank myBank("12345", 2000.0);

	shop(myStore, myCart, myBank);

	return 0;
}