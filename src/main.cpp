// file: main.cpp
#include <iostream>

#include "mylist_1/mylist_1.h"
#include "myvector/myvector.h"

int main() {
    std::cout << std::endl;

    MyList_1<int> list{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // list.print();
    std::cout << std::endl;

    // std::cout << "Удаление из пустого списка" << std::endl;
    // list = MyList_1<int>();
    // list.erase(0);
    // list.print();
    // std::cout << std::endl;

    std::cout << "Удаление единственного элемента (index = 0)" << std::endl;
    list = {777};
    list.print();
    std::cout << std::endl;
    list.erase(0);
    list.print();
    std::cout << std::endl;

    std::cout << "Удаление первого элемента из списка" << std::endl;
    list = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    list.print();
    list.erase(0);
    list.print();
    std::cout << std::endl;

    std::cout << "Удаление последнего элемента из списка" << std::endl;
    list.erase(list.size() - 1);
    list.print();
    std::cout << std::endl;

    std::cout << "Удаление предпоследнего элемента" << std::endl;
    list.erase(list.size() - 2);
    list.print();
    std::cout << std::endl;

    std::cout << "Удаление из середины списка" << std::endl;
    list.erase(4);
    list.print();
    std::cout << std::endl;

    std::cout << "Удаление с index >= size" << std::endl;
    list.erase(11);
    list.print();
    std::cout << std::endl;

    std::cout << std::endl;
    return 0;
}