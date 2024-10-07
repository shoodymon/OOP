#pragma once

#include "includes.hpp"

class Item {
protected:
	std::string m_name;
	double m_price;

public:
	Item(const std::string& name, double price) : m_name(name), m_price(price) {}
	virtual ~Item() = default;

	virtual void display() const = 0;
	virtual double getPrice() const { return m_price; }

	std::string getName() const { return m_name; }
	void setName(const std::string& name) { m_name = name; }
	void setPrice(double price) { m_price = price; }
};

class Product : public Item {
private:
	std::string m_manufacturer;

public:
	Product(const std::string& name, const std::string& manufacturer, double price) 
		: Item(name, price), m_manufacturer(manufacturer) {}

	void display() const override {
		std::cout << "Продукт: " << m_name << " сделан " << m_manufacturer << ", цена: $ " << m_price << std::endl;
	}

	std::string getManufacturer() const { return m_manufacturer; }
	void setManufacturer(const std::string& manufacturer) { m_manufacturer = manufacturer; }
};

class Service : public Item {
private:
	int m_duration;

public:
	Service(const std::string& name, double price, int duration)
		: Item(name, price), m_duration(duration) {}

	void display() const override {
		std::cout << "Обслуживание: " << m_name << ", время: " << m_duration << " минут, цена: $ " << m_price << std::endl;
	}

	int getDuration() const { return m_duration; }
	void setDuration(int duration) { m_duration = duration; }
};