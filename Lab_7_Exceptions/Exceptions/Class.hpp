#pragma once
#include <iostream>
#include <cmath>
#include <exception>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>

class CustomException : public std::exception {
private:
    std::string message;
public:
    explicit CustomException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class ArrayProcessor {
private:
    std::vector<double> a; // Массив A
    std::vector<int> b;    // Массив B
    std::vector<double> c; // Массив C

    double calculateFunction(double x) {
        if (x + 1 <= 0) {
            throw CustomException("Массив А: Логарифм от отрицательного числа или нуля.");
        }
        return std::log(1 / (x + 1));
    }

public:
    void fillArrayA(int size, double startX, double endX, double deltaX) {
        double x = startX;
        for (int i = 0; i < size; ++i) {
            try {
                if (x < startX || x > endX) {
                    throw CustomException("Массив А: x выходит за пределы диапазона");
                }
                a.push_back(calculateFunction(x));
            }
            catch (const CustomException& e) {
                std::cerr << "Ошибка при вычислении a[" << i << "]: " << e.what() << std::endl;
                a.push_back(0);
            }
            x += deltaX;
        }
    }

    void fillArrayB(int size) {
        std::srand(static_cast<unsigned>(std::time(nullptr)));
        for (int i = 0; i < size; ++i) {
            int randomValue = (std::rand() % 201) - 100;
            if (randomValue < std::numeric_limits<int>::min() || randomValue > std::numeric_limits<int>::max()) {
                throw CustomException("Массив B: Возможное переполнение при генерации числа");
            }
            b.push_back(randomValue);
        }
    }

    void calculateArrayC(int size) {
        for (int i = 0; i < size; ++i) {
            try {
                if (i >= a.size()) {
                    throw CustomException("Массив С: Выход массива за границы a");
                }
                if (i + 1 >= b.size()) {
                    throw CustomException("Массив С: Выход массива за границы b");
                }
                if (b[i + 1] == 0) {
                    throw CustomException("Массив С: Деление на ноль");
                }
                if (std::abs(a[i]) > std::numeric_limits<double>::max() ||
                    std::abs(b[i + 1]) > std::numeric_limits<int>::max()) {
                    throw CustomException("Массив С: Возможное переполнение при делении");
                }
                c.push_back(a[i] / b[i + 1]);
            }
            catch (const CustomException& e) {
                std::cerr << "Ошибка при вычислении c[" << c.size() << "]: " << e.what() << std::endl;
                c.push_back(0);
            }
        }
    }

    template<typename T>
    void printArray(const std::vector<T>& array, const std::string& name) const {
        std::cout << "\nМассив " << name << ":\n";
        for (const auto& value : array) {
            std::cout << value << ' ';
        }
        std::cout << '\n';
    }

    void printAll() const {
        printArray(a, "a");
        printArray(b, "b");
        printArray(c, "c");
    }
};
