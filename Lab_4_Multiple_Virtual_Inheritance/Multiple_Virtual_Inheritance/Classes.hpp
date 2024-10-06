#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>

class B {
protected:
	std::string m_name;
	int m_age;

public:
	B(const std::string& name, int age) : m_name(name), m_age(age) {}
	virtual ~B() = default; // для корректного удаления объектов через указатели на базовый класс

	virtual void show() const {
		std::cout << "\n\t\tB: " << "\n\t---------------" << "\n\tИмя: " << m_name << "\n\tВозраст: " << m_age << "\n\t---------------" << std::endl;
	}
};

class D1 : public B {
public:
	D1(const std::string& name, int age) : B(name, age) {}

	virtual void show() const override {
		std::cout << "\n\t\tD1: " << "\n\t---------------" << "\n\tИмя: " << m_name << "\n\tВозраст: " << m_age << "\n\t---------------" << std::endl;
	}
};

class D2 : private B {
public:
	D2(const std::string& name, int age) : B(name, age) {}

	virtual void show() const override {
		std::cout << "\n\t\tD2: " << "\n\t---------------" << "\n\tИмя: " << m_name << "\n\tВозраст: " << m_age << "\n\t---------------" << std::endl;
	}
};

class D3 : private D1, public D2 {
public:
	D3(const std::string& name1, int age1, const std::string& name2, int age2) : D1(name1, age1), D2(name2, age2) {}

	virtual void show() const override {
		D1::show();
		D2::show();
	}
};