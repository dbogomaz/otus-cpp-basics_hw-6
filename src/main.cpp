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
    // MyVector<int> vec(10);

    std::cout << "Capacity: " << vec.capacity() << std::endl;
    std::cout << "Size: " << vec.size() << std::endl;
    std::cout << "MyVector: " << vec << std::endl;

    return 0;
}