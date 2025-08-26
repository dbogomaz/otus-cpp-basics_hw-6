// file: main.cpp
#include <iostream>

#include "myvector/myvector.h"
#include "mylist_1/mylist_1.h"

int main() {
    std::cout << "*****************" << std::endl;

    MyList_1<int> list{0, 1, 2, 3, 4};
    list.print();
    std::cout << std::endl;
    MyList_1<int> list2 = MyList_1<int>{5, 6, 7, 8, 9};
    list2.print();
    std::cout << std::endl;
    std::cout << "List1: " << list << std::endl;
    std::cout << "List2: " << list2 << std::endl;



    return 0;
}