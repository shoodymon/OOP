#include "Class.hpp"

int main() {
    setlocale(LC_ALL, "Russian");

    try {
        ArrayProcessor processor;

        int sizeA = 10, sizeB = 15, sizeC = 10;
        double startX = -2, endX = 4, deltaX = 0.3;

        processor.fillArrayA(sizeA, startX, endX, deltaX);
        processor.fillArrayB(sizeB);
        processor.calculateArrayC(sizeC);

        processor.printAll();
    }
    catch (const std::exception& e) {
        std::cerr << "Общая ошибка: " << e.what() << '\n';
    }

    return 0;
}
