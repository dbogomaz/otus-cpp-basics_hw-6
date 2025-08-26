// file: main.cpp
#include <iostream>

#include "myvector/myvector.h"
#include "mylist_1/mylist_1.h"

int main() {
    std::cout << "*****************" << std::endl;

    MyList_1<int> list{0, 1, 2, 3, 4};
    list.print();
    std::cout << std::endl;
    MyList_1<int> list2(std::move(list));
    list2.print();
    std::cout << std::endl;
    list.print();


    return 0;
}