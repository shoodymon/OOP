#include "prototypes.hpp"

int main() {
    // ������ � ���������
    int value = 5;
    increment(value);  // �������� �� ���������
    std::cout << "\n\tAfter increment (no ref): " << value << std::endl;  // 5

    incrementRef(value);  // �������� ���������
    std::cout << "\tAfter incrementRef: " << value << std::endl;  // 6

    // ������ � ������������� ��������
    MyClass1 obj1(10);
    obj1.display();  // 10
    incrementFriend(obj1); 
    obj1.display();  // 11

    // ������ � ����������� ���������
    MyClass2 obj2(20);
    obj2.display();  // 20
    ++obj2;  
    obj2.display();  // 21

    return 0;
}
