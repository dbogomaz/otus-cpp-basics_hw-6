// file: main.cpp
#include <iostream>

#include "myvector/myvector.h"
#include "mylist_1/mylist_1.h"

int main() {
    std::cout << "*****************" << std::endl;

    MyList_1<int> list{0, 1, 2, 3, 4};
    list.print();
    std::cout << std::endl;
    MyList_1<int> list2 = MyList_1<int>{0, 1, 2, 3, 4, 5};
    list2.print();
    std::cout << std::endl;
    std::cout << (list == list2) << std::endl;
    std::cout << (list != list2) << std::endl;



    return 0;
}