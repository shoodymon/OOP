#pragma once

#include <iostream>


void increment(int value);
int& incrementRef(int& value);

class MyClass1 {
private:
	int m_value;

public:
    MyClass1(int v);

    // Делаем функцию дружественной классу MyClass1
	friend void incrementFriend(MyClass1& obj);
    void display() const;
};

void incrementFriend(MyClass1& obj);

class MyClass2 {
private:
    int m_value;

public:
    MyClass2(int v);

    MyClass2& operator++();
    MyClass2 operator++(int);

    int getValue() const;
    void display() const;
};

class MyClass3 {
private:
    int m_value;

public:
    MyClass3(int v);

    MyClass3& operator++();
    MyClass3 operator++(int);

    int getValue() const;
    void display() const;
};