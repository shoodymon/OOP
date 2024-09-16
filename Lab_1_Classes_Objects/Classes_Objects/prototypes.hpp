#pragma once

#include <iostream>
#include <iomanip>

class Time {
private:
    int m_hours;
    int m_minutes;
    int m_seconds;

    void validateTime();

public:
    Time(int h = 0, int m = 0, int s = 0) : m_hours(h), m_minutes(m), m_seconds(s) {
        setlocale(0, "");
        validateTime();
    }

    ~Time() {
        std::cout << "\n\tОбъект Time удалён" << std::endl;
    }

    void setTime(int h, int m, int s);
    int getHours() const&;
    int getMinutes() const&;
    int getSeconds() const&; // не изменяет объект, на который указывает скрытый указатель this
    void printFormat1();
    void printFormat2();
};