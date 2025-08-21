// file: myvector.h
#ifndef MYVECTOR_H
#define MYVECTOR_H

template <typename T>
class MyVector {
public:
    explicit MyVector(const size_t size = 0);
    MyVector(const std::initializer_list<T> initList);
    MyVector(const MyVector &other);
    MyVector(MyVector &&other) noexcept;
    MyVector &operator=(const MyVector &other);
    MyVector &operator=(MyVector &&other) noexcept;
    ~MyVector();

    void push_back(const T& value);
    void insert(const size_t index, const T& value);
    size_t capacity() const;
    size_t size() const;
    void reserve(const size_t new_capacity);
    T &at(const size_t index);
    const T &at(size_t index) const;

    void print() const;

    T &operator[](const size_t index);
    const T &operator[](const size_t index) const;

private:
    size_t m_capacity{1};                          // вместимость
    size_t m_size{0};                              // текущий размер
    static constexpr float CAPACITY_FACTOR{1.5f};  // коэффициент выделения памяти
    T *m_data{nullptr};

    void copyFrom(const MyVector &other);
    void moveFrom(MyVector &&other) noexcept;
    void checkIndex(const size_t index, const char *function_name) const;
    void growCapacity(); // увеличение вместимости
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const MyVector<T> &myVector);

#include "myvector.ipp"

#endif  // MYVECTOR_H