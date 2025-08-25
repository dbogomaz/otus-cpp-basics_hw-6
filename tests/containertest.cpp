// @file containertest.cpp
#include <iostream>
#include <cassert>
// #include <sstream>

#include "../src/myvector/myvector.h"

namespace tests {

template <typename T>
void containerTest() {
    T container{0, 1, 2, 3, 4};
    const T expected_seq{0, 1, 2, 3, 4};
	for (size_t i = 0; i < container.size(); ++i) {
		assert(container[i] == expected_seq[i] && "Values are not equal");
	}



    // // 1. создание объекта контейнера для хранения объектов типа int
    // T container{0, 1, 2, 3, 4};
    // // 2. добавление в контейнер десяти элементов (0, 1 … 9)
    // for (size_t value = 5; value < 10; value++) {
    //     container.push_back(value);
    // }
    // // 3. вывод содержимого контейнера на экран
    // // ожидаемый результат: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    // std::cout << container << std::endl;
    // // 4. вывод размера контейнера на экран
    // // ожидаемый результат: 10
    // std::cout << container.size() << std::endl;
    // // 5. удаление третьего (по счёту), пятого и седьмого элементов
    // container.erase(7 - 1);
    // container.erase(5 - 1);
    // container.erase(3 - 1);
    // // 6. вывод содержимого контейнера на экран
    // // ожидаемый результат: 0, 1, 3, 5, 7, 8, 9
    // std::cout << container << std::endl;
    // // 7. добавление элемента 10 в начало контейнера
    // container.insert(0, 10);
    // // 8. вывод содержимого контейнера на экран
    // // ожидаемый результат: 10, 0, 1, 3, 5, 7, 8, 9
    // std::cout << container << std::endl;
    // // 9. добавление элемента 20 в середину контейнера
    // container.insert(container.size() / 2, 20);
    // // 10. вывод содержимого контейнера на экран
    // // ожидаемый результат: 10, 0, 1, 3, 20, 5, 7, 8, 9
    // std::cout << container << std::endl;
    // // 11. добавление элемента 30 в конец контейнера
    // container.push_back(30);
    // // 12. вывод содержимого контейнера на экран
    // // ожидаемый результат: 10, 0, 1, 3, 20, 5, 7, 8, 9, 30
    // std::cout << container << std::endl;

    // for (auto iter = container.begin(); iter != container.end(); ++iter) {
    //     std::cout << *iter << std::endl;
    // }
}

}  // namespace tests

int main() {
    tests::containerTest<MyVector<int>>();
    std::cout << "Test passed" << '\n';
}
