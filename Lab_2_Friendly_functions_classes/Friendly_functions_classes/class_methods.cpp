#include "prototypes.hpp"
// const - не изменим объект через ссылку, const& - гарантия неизменности объекта

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

// Префиксный оператор инкремента (для сравнения)
MyClass2& MyClass2::operator++() {
    m_value++;
    return *this;                   // ссылка на текущий объект
}

// Постфиксный оператор инкремента (вариант 1)
MyClass2 MyClass2::operator++(int) {
    MyClass2 temp = *this;          // Создаем копию текущего объекта (временный объект с текущим значением)
    ++m_value;                      // Увеличиваем значение
    return temp;                    // Возвращаем неизмененную копию
}

// Постфиксный оператор инкремента (вариант 2)
// Подход увеличения значения предполагает, что у класса уже определен префиксный оператор инкремента, и использует его
MyClass3 MyClass3::operator++(int) {
    MyClass3 copy{ *this };         // Создаем копию текущего объекта
    ++(*this);                      // Увеличиваем текущий объект 
    return copy;                    // Возвращаем неизмененную копию
}

int MyClass2::getValue() const {
    return m_value;
}

void MyClass2::display() const {
    std::cout << "\tMyClass2 value: " << m_value << std::endl;
}

MyClass3::MyClass3(int v) : m_value(v) {}

MyClass3& MyClass3::operator++() {
    m_value++;
    return *this;                   // ссылка на текущий объект
}

int MyClass3::getValue() const {
    return m_value;
}

void MyClass3::display() const {
    std::cout << "\tMyClass3 value: " << m_value << std::endl;
}