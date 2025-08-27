// @file: mylist_1.h
#ifndef MYLIST_1_H
#define MYLIST_1_H

template <typename T>
class MyList_1 {
public:
    class Node;

    class iterator;
    class const_iterator;

    explicit MyList_1(const size_t size = 0); // конструктор по умолчанию и с параметром размера
    MyList_1(const std::initializer_list<T> initList); // конструктор инициализации списком
    MyList_1(const MyList_1 &other); // конструктор копирования
    MyList_1(MyList_1 &&other) noexcept; // конструктор перемещения
    MyList_1 &operator=(const MyList_1 &other); // оператор присваивания копированием
    MyList_1 &operator=(MyList_1 &&other) noexcept; // оператор присваивания перемещением
    bool operator==(const MyList_1 &other) const; // оператор сравнения
    bool operator!=(const MyList_1 &other) const; // оператора сравнения
    ~MyList_1(); // деструктор

    void push_back(const T &value);
    void insert(const size_t index, const T &value);
    void erase(const size_t index);
    void clear(); // очистка списка
    size_t capacity() const;
    size_t size() const; // текущий размер
    void reserve(const size_t new_capacity);
    
    T &at(const size_t index);
    const T &at(size_t index) const;
    T &operator[](const size_t index);
    const T &operator[](const size_t index) const;

    iterator begin() noexcept;
    iterator end() noexcept;
    const_iterator begin() const noexcept;
    const_iterator end() const noexcept;

    void print() const; // вывод в консоль



private:
    size_t m_capacity{1};                          // вместимость
    size_t m_size{0};                              // текущий размер
    static constexpr float CAPACITY_FACTOR{1.5f};  // коэффициент выделения памяти
    T *m_data{nullptr};
    Node *m_firstNode{nullptr};  // указатель на первый элемент
    Node *m_lastNode{nullptr};   // указатель на последний элемент

    void copyFrom(const MyList_1 &other); // копирование из другого списка
    void moveFrom(MyList_1 &&other) noexcept; // перемещение из другого списка
    void checkIndex(const size_t index, const char *function_name) const; // проверка индекса
    void growCapacity();
};

template <typename T>
class MyList_1<T>::Node {
public:
    Node *next{nullptr};  // указатель на следующий элемент
    T data{};             // данные элемента
};

template <typename T>
class MyList_1<T>::iterator {
public:
    explicit iterator(T *ptr = nullptr);
    T &operator*() const;
    T *get() const;
    iterator &operator++();
    iterator operator++(int);
    bool operator==(const iterator &other) const;
    bool operator!=(const iterator &other) const;

private:
    T *m_ptr;
};

template <typename T>
class MyList_1<T>::const_iterator {
public:
    explicit const_iterator(const T *ptr = nullptr);
    const T &operator*() const;
    const T *get() const;
    const_iterator &operator++();
    const_iterator operator++(int);
    bool operator==(const const_iterator &other) const;
    bool operator!=(const const_iterator &other) const;

private:
    const T *m_ptr;
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const MyList_1<T> &myVector);

#include "mylist_1.ipp"

#endif  // MYLIST_1_H