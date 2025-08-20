// file: main.cpp
#include <iostream>

#include "myvector/myvector.h"

int main() {
    std::cout << "*****************" << std::endl;

    MyVector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    vec.reserve(10);

    std::cout << "Capacity: " << vec.capacity() << std::endl;
    std::cout << "Size: " << vec.size() << std::endl;
    std::cout << "MyVector: " << vec << std::endl;

    vec.at(2) = 111;

    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec.at(i) << " ";
    }

    std::cout << std::endl;

    std::cout << vec;

    std::cout << std::endl;

    return 0;
}