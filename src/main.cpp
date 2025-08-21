// file: main.cpp
#include <iostream>

#include "myvector/myvector.h"

int main() {
    std::cout << "*****************" << std::endl;

    MyVector<int> vec{0, 1, 2, 3, 4};
    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(7);
    vec.push_back(8);
    vec.push_back(9);
    // vec.push_back(10);

    vec.print();

    vec.erase(0);
    vec.print();
}