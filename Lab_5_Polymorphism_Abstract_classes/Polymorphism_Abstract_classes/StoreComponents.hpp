#pragma once

#include "includes.hpp"
#include "Items.hpp"

class StoreComponent {
protected:
	std::string m_name;

public:
	StoreComponent(const std::string& name) : m_name(name) {}
	virtual ~StoreComponent() = default;

	virtual void display() const = 0;

	std::string getName() { return m_name; }
	void setName(const std::string& name) { m_name = name; }
};

class Department : public StoreComponent {
private:
	std::vector<std::shared_ptr<Item>> m_items;

public:
	Department(const std::string& name) : StoreComponent(name) {}

	void addItem(const std::shared_ptr<Item>& item) { m_items.push_back(item); }
	const std::vector<std::shared_ptr<Item>>& getItems() const { return m_items; }

	void display() const override {
		std::cout << "Отдел: " << m_name << std::endl;
		for (const auto& item : m_items) {
			item->display();
		}
	}
};

class Store : public StoreComponent {
private:
	std::string m_type;
	std::vector<Department> m_departments;

public:
	Store(const std::string& name, const std::string& type) 
		: StoreComponent(name), m_type(type) {}

	std::string getType() const { return m_type; }
	void setType(const std::string& type) { m_type = type; }

	void addDepartment(const Department& department) { m_departments.push_back(department); }
	const std::vector<Department>& getDepartments() const { return m_departments; }

	void display() const override {
		std::cout << "Магазин: " << m_name << ", Тип: " << m_type << std::endl;
		for (const auto& department : m_departments) {
			department.display();
		}
	}
};

class Cart : public StoreComponent {
private:
	std::vector<std::shared_ptr<Item>> m_items;

public:
	Cart() : StoreComponent("Корзина покупок") {}

	void addItem(const std::shared_ptr<Item>& item) { m_items.push_back(item); }

	double getTotal() const {
		double total = 0;
		for (const auto& item : m_items) {
			total += item->getPrice();
		}
		return total;
	}

	void display() const override {
		std::cout << "Содержимое корзины: " << std::endl;
		for (const auto& item : m_items) {
			item->display();
		}
		std::cout << "Всего: $ " << getTotal() << std::endl;
	}
};
