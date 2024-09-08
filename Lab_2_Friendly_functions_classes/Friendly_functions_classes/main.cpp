#include "prototypes.hpp"

int main() {
    // Работа с функциями
    int value = 5;
    increment(value);  // Значение не изменится
    std::cout << "\n\tAfter increment (no ref): " << value << std::endl;  // 5

    incrementRef(value);  // Значение изменится
    std::cout << "\tAfter incrementRef: " << value << std::endl;  // 6

    // Работа с дружественной функцией
    MyClass1 obj1(10);
    obj1.display();  // 10
    incrementFriend(obj1); 
    obj1.display();  // 11

    // Работа с перегрузкой оператора
    MyClass2 obj2(20);
    obj2.display();  // 20
    ++obj2;  
    obj2.display();  // 21

    return 0;
}
