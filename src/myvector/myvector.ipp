// file: myvector.ipp

#include <sstream>
#include <stdexcept>

#include "myvector.h"

template <typename T>
MyVector<T>::MyVector(const size_t size) : m_size{size} {
    if (m_size > 0) {
        m_capacity = static_cast<size_t>(m_size * m_capacityFactor);
    }
    m_data = new T[m_capacity];
}

template <typename T>
MyVector<T>::MyVector(const std::initializer_list<T> initList) : m_size{initList.size()} {
    if (m_size > 0) {
        m_capacity = static_cast<size_t>(m_size * m_capacityFactor);
    }
    m_data = new T[m_capacity];

    if (m_size > 0) {
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
MyVector<T>::MyVector(MyVector &&other) noexcept {
    moveFrom(std::move(other));
}

template <typename T>
void MyVector<T>::moveFrom(MyVector&& other) noexcept {
    m_capacity = other.m_capacity;
    m_size = other.m_size;
    m_capacityFactor = other.m_capacityFactor;
    m_data = other.m_data;

    other.m_capacity = 0;
    other.m_size = 0;
    other.m_data = nullptr;
}

template <typename T>
T &MyVector<T>::at(const size_t index) {
    checkIndex(index, "at");
    return m_data[index];
}

template <typename T>
const T &MyVector<T>::at(const size_t index) const {
    checkIndex(index, "at");
    return m_data[index];
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
MyVector<T> &MyVector<T>::operator=(MyVector &&other) noexcept {
    if (this != &other) {
        delete[] m_data;
        moveFrom(std::move(other));
    }
    return *this;
}

template <typename T>
T &MyVector<T>::operator[](const size_t index) {
    checkIndex(index, "operator[]");
    return m_data[index];
}

template <typename T>
const T &MyVector<T>::operator[](const size_t index) const {
    checkIndex(index, "operator[]");
    return m_data[index];
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const MyVector<T> &myVector) {
    for (size_t i = 0; i < myVector.size(); ++i) {
        os << myVector.at(i) << " ";
    }
    return os;
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
void MyVector<T>::reserve(const size_t new_capacity) {
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

template <typename T>
void MyVector<T>::checkIndex(const size_t index, const char *function_name) const {
    if (index >= m_size) {
        std::ostringstream oss;
        oss << "MyVector::" << function_name << "(): index " << index
            << " out of range (size: " << m_size << ")";
        throw std::out_of_range(oss.str());
    }
}
