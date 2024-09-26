#include "prototypes.hpp"

int main() {
    int value = 5;
    increment(value);  // Значение не изменится
    std::cout << "\n\tAfter increment (no ref): " << value << std::endl;  

    incrementRef(value);  // Значение изменится
    std::cout << "\tAfter incrementRef: " << value << std::endl;  

    MyClass1 obj1(10);
    obj1.display();
    incrementFriend(obj1); 
    obj1.display();

    MyClass2 obj2(20);
    obj2.display(); 
    ++obj2;  
    obj2.display(); 

    MyClass2 obj3(30);
    obj3.display();
    obj3++;
    obj3.display();

    MyClass3 obj4(40);
    obj4.display();
    obj4++;
    obj4.display();

    return 0;
}
