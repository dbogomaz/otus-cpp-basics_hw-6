// file: myvector.ipp

#include <stdexcept>

#include "myvector.h"

template <typename T>
MyVector<T>::MyVector(size_t size) : m_size{size} {
    m_capacity = static_cast<size_t>(m_size * m_capacityFactor);
    if (m_size > 0) {
        m_data = new T[m_capacity];
    }
}

template <typename T>
inline MyVector<T>::MyVector(std::initializer_list<T> initList) : m_size{initList.size()} {
    m_capacity = static_cast<size_t>(m_size * m_capacityFactor);
    if (m_size > 0) {
        m_data = new T[m_capacity];
        size_t i = 0;
        for (const auto &item : initList) {
            m_data[i++] = item;
        }
    }
}

template <typename T>
MyVector<T>::MyVector(const MyVector &other) {
    copyFrom(other);
}

template <typename T>
MyVector<T> &MyVector<T>::operator=(const MyVector &other) {
    if (this != &other) {
        delete[] m_data;
        copyFrom(other);
    }
    return *this;
}

template <typename T>
MyVector<T>::~MyVector() {
    delete[] m_data;
}

template <typename T>
size_t MyVector<T>::capacity() const {
    return m_capacity;
}

template <typename T>
size_t MyVector<T>::size() const {
    return m_size;
}

template <typename T>
void MyVector<T>::reserve(size_t new_capacity) {
    if (new_capacity > m_capacity) {
        T *new_data = new T[new_capacity];
        for (size_t i = 0; i < m_size; ++i) {
            new_data[i] = m_data[i];
        }
        delete[] m_data;
        m_data = new_data;
        m_capacity = new_capacity;
    }
}

template <typename T>
void MyVector<T>::copyFrom(const MyVector &other) {
    m_capacity = other.m_capacity;
    m_size = other.m_size;
    m_data = new T[m_capacity];
    for (size_t i = 0; i < m_size; ++i) {
        m_data[i] = other.m_data[i];
    }
}
