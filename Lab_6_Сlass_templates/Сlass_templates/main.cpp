#include "class.hpp"

int main() {
    setlocale(0, "");
    system("chcp1251");
    system("cls");

    ListElement<int>* list1 = new ListElement<int>(5);
    list1 = list1->addToStart(3);
    list1 = list1->addToStart(1);

    ListElement<int>* list2 = new ListElement<int>(10);
    list2 = list2->addToStart(7);

    std::cout << "\n\tСписок 1: " << list1 << std::endl;
    std::cout << "\tСписок 2: " << list2 << std::endl;
    std::cout << "\tКоличество элементов: " << ListElement<int>::getCount() << std::endl;

    std::cout << "\n\tРазмеры списков равны? " << (*list1 == *list2) << std::endl;

    list1 = list1->removeFromStart();
    std::cout << "\n\tСписок 1: " << list1 << std::endl;
    list2 = list2->removeFromStart();
    std::cout << "\tСписок 2: " << list2 << std::endl;
    std::cout << "\tКоличество элементов: " << ListElement<int>::getCount() << std::endl;

    ListElement<int>* found = list1->find(5);
    if (found) {
        std::cout << "\n\tЭлемент 5 найден" << std::endl;
    }
    else {
        std::cout << "\tЭлемент 5 не найден" << std::endl;
    }

    ListElement<int>::deleteList(list1);
    ListElement<int>::deleteList(list2);
    std::cout << "\n\tКоличество элементов после удаления: " << ListElement<int>::getCount() << std::endl;

    return 0;
}
