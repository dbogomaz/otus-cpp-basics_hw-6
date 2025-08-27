// file: main.cpp
#include <cassert>
#include <iostream>

#include "mylist_1/mylist_1.h"
#include "mylist_2/mylist_2.h"
#include "myvector/myvector.h"

int main() {
    std::cout << std::endl;

    MyList_2<int> list{0, 1, 2, 3, 4};
    list.print();
    std::cout << std::endl;
    list.erase(4);
    list.print();


    // std::cout << list << std::endl;

    std::cout << std::endl;
    return 0;
}