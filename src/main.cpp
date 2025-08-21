// file: main.cpp
#include <iostream>

#include "myvector/myvector.h"
#include "containertest.h"

int main() {
    std::cout << "*****************" << std::endl;

    containerTest<MyVector<int>>();
}