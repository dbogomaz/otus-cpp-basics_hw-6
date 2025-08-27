// file: main.cpp
#include <cassert>
#include <iostream>

#include "mylist_1/mylist_1.h"
#include "myvector/myvector.h"

int main() {
    std::cout << std::endl;

    MyList_1<int> list{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    list.print();
    std::cout << std::endl;

    // Тест 1: Итерация по списку
    std::cout << "Итерация по списку: ";
    for (auto it = list.begin(); it != list.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Тест 2: Проход по контейнеру
    std::cout << "Проход по контейнеру: ";
    for (int value : list) {
        std::cout << value << " ";
    }

    // Тест 3: Пустой список
    list.clear();
    assert(list.begin() == list.end());
    std::cout << "\nТест Пустой список" << std::endl;

    list = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // Тест 4: Префиксный инкремент
    auto it = list.begin();
    assert(*it == 0);
    ++it;
    assert(*it == 1);

    // Тест 5: Постфиксный инкремент
    it = list.begin();
    assert(*it == 0);    // Текущее значение
    int value = *it++;   // Сохраняем старое значение и инкрементируем
    assert(value == 0);  // Проверяем возвращенное значение
    assert(*it == 1);    // Проверяем новое значение

    // Тест 6: Многократный инкремент
    it = list.begin();
    ++ ++it;  // Двойной инкремент
    assert(*it == 2);

    // Тест 7: Сравнение итераторов
    auto it1 = list.begin();
    auto it2 = list.begin();
    assert(it1 == it2);
    ++it1;
    assert(it1 != it2);

    // Тест 8: Оператор get
    struct TestStruct {
        int x;
    };
    MyList_1<TestStruct> structList;
    structList.push_back({42});
    assert(structList.begin().get()->x == 42);

    std::cout << std::endl;
    return 0;
}