// file: main.cpp
#include <iostream>

#include "myvector/myvector.h"
#include "mylist_1/mylist_1.h"

int main() {
    std::cout << std::endl;

    MyList_1<int> list{0, 1, 2, 3, 4};
    list.print();
    std::cout << std::endl;
    list.push_back(5);
    list.push_back(6);
    list.push_back(7);
    list.push_back(8);
    list.push_back(9);
    list.print();

    std::cout << std::endl;
    return 0;
}