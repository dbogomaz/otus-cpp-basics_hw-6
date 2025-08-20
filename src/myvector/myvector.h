// file: myvector.h
#ifndef MYVECTOR_H
#define MYVECTOR_H

template <typename T>
class MyVector {
public:
    explicit MyVector(size_t size = 0);
    MyVector(std::initializer_list<T> initList);
    MyVector(const MyVector& other);
    ~MyVector();

    MyVector& operator=(const MyVector& other);

    size_t capacity() const;
    size_t size() const;
    void reserve(size_t new_capacity);

private:
    size_t m_capacity{0};         // вместимость
    size_t m_size{0};             // текущий размер
    float m_capacityFactor{1.5};  // коэффициент выделения памяти
    T* m_data{nullptr};
    
    void copyFrom(const MyVector& other);
};

#include "myvector.ipp"

#endif  // MYVECTOR_H