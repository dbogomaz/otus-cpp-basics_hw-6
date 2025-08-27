// file: main.cpp
#include <iostream>

#include "mylist_1/mylist_1.h"
#include "myvector/myvector.h"

int main() {
    std::cout << std::endl;

    MyList_1<int> list;
    list.print();
    std::cout << std::endl;

    std::cout << "Вставка в пустой список (index = 0)" << std::endl;
    list.insert(0, 2);
    list.print();
    std::cout << std::endl;

    std::cout << "Вставка в начало непустого списка (index = 0)" << std::endl;
    list.insert(0, 0);
    list.print();
    std::cout << std::endl;

    std::cout << "Вставка в конец списка (index = size)" << std::endl;
    list.insert(list.size(), 4);
    list.print();
    std::cout << std::endl;

    std::cout << "Вставка сразу после начала (index = 1)" << std::endl;
    list.insert(1, 1);
    list.print();
    std::cout << std::endl;

    std::cout << "Вставка сразу перед концом (index = size-1)" << std::endl;
    list.insert(list.size() - 1, 3);
    list.print();
    std::cout << std::endl;

    std::cout << std::endl;
    return 0;
}