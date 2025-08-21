// file: main.cpp
#include <iostream>

#include "myvector/myvector.h"

int main() {
    std::cout << "*****************" << std::endl;

    // MyVector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    MyVector<int> vec(10);

    std::cout << "Capacity: " << vec.capacity() << std::endl;
    std::cout << "Size: " << vec.size() << std::endl;
    std::cout << "MyVector: " << vec << std::endl;

    return 0;
}