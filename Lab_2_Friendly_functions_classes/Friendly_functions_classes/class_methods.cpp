#include "prototypes.hpp"

// ������� ���������� (�� ��������� ���������)
void increment(int value) {
	value++;
}

// �������, ������������ ������ �� �������� � ���������� ���
int& incrementRef(int& value) {
    value++;
    return value;
}

MyClass1::MyClass1(int v) : m_value(v) {}

// ������� incrementFriend() ������ �������� ������ ������ MyClass1 
void incrementFriend(MyClass1& obj) {
    obj.m_value++;
}

void MyClass1::display() const {
    std::cout << "\tMyClass1 value: " << m_value << std::endl;
}

MyClass2::MyClass2(int v) : m_value(v) {}

// ���������� ���������� ��������� ++ ��� MyClass2
MyClass2& MyClass2::operator++() {
    m_value++;
    return *this;
}

int MyClass2::getValue() const {
    return m_value;
}

void MyClass2::display() const {
    std::cout << "\tMyClass2 value: " << m_value << std::endl;
}