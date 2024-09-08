#include "prototypes.hpp"

// Функция инкремента (не сохраняет изменение)
void increment(int value) {
	value++;
}

// Функция, возвращающая ссылку на параметр и изменяющая его
int& incrementRef(int& value) {
    value++;
    return value;
}

MyClass1::MyClass1(int v) : m_value(v) {}

// Функция incrementFriend() теперь является другом класса MyClass1 
void incrementFriend(MyClass1& obj) {
    obj.m_value++;
}

void MyClass1::display() const {
    std::cout << "\tMyClass1 value: " << m_value << std::endl;
}

MyClass2::MyClass2(int v) : m_value(v) {}

// Реализация перегрузки оператора ++ для MyClass2
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