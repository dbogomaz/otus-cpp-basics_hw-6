// file: main.cpp
#include <iostream>

#include "myvector/myvector.h"

int main() {
    std::cout << "*****************" << std::endl;

    MyVector<int> vec{0, 1};

    vec.reserve(10);

    std::cout << "Capacity: " << vec.capacity() << std::endl;
    std::cout << "Size: " << vec.size() << std::endl;

    return 0;
}