// file: main.cpp
#include <cassert>
#include <iostream>

#include "mylist_1/mylist_1.h"
#include "myvector/myvector.h"

int main() {
    std::cout << std::endl;

    MyList_1<int> list{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    list.print();
    std::cout << std::endl;

    std::cout << list << std::endl;

    std::cout << std::endl;
    return 0;
}