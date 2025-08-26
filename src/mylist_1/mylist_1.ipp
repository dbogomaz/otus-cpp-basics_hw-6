// @file: myvector.ipp

#include <sstream>
#include <stdexcept>

#include "mylist_1.h"

template <typename T>
MyList_1<T>::MyList_1(const size_t size) : m_size{size} {
    if (m_size > 0) {
        m_firstNode = new Node();
        m_lastNode = m_firstNode;

        for (size_t i = 1; i < m_size; i++) {
            Node *newNode = new Node();
            m_lastNode->next = newNode;
            m_lastNode = newNode;
        }
    }
}

template <typename T>
MyList_1<T>::MyList_1(const std::initializer_list<T> initList) : m_size{initList.size()} {
    if (m_size > 0) {
        auto it = initList.begin();
        m_firstNode = new Node();
        m_firstNode->data = *it;
        m_lastNode = m_firstNode;
        ++it;

        for (size_t i = 1; i < m_size; i++) {
            Node *newNode = new Node();
            newNode->data = *it;
            m_lastNode->next = newNode;
            m_lastNode = newNode;
            ++it;
        }
    }
}

template <typename T>
MyList_1<T>::MyList_1(const MyList_1 &other) {
    copyFrom(other);
}

template <typename T>
MyList_1<T>::MyList_1(MyList_1 &&other) noexcept {
    moveFrom(std::move(other));
}

template <typename T>
void MyList_1<T>::moveFrom(MyList_1 &&other) noexcept {
    m_capacity = other.m_capacity;
    m_size = other.m_size;
    m_data = other.m_data;

    other.m_capacity = 0;
    other.m_size = 0;
    other.m_data = nullptr;
}

template <typename T>
T &MyList_1<T>::at(const size_t index) {
    checkIndex(index, "at");
    return m_data[index];
}

template <typename T>
const T &MyList_1<T>::at(const size_t index) const {
    checkIndex(index, "at");
    return m_data[index];
}

template <typename T>
MyList_1<T> &MyList_1<T>::operator=(const MyList_1 &other) {
    if (this != &other) {
        delete[] m_data;
        copyFrom(other);
    }
    return *this;
}

template <typename T>
MyList_1<T> &MyList_1<T>::operator=(MyList_1 &&other) noexcept {
    if (this != &other) {
        delete[] m_data;
        moveFrom(std::move(other));
    }
    return *this;
}

template <typename T>
bool MyList_1<T>::operator==(const MyList_1 &other) const {
    if (m_size != other.m_size) {
        return false;
    }

    for (size_t i = 0; i < m_size; ++i) {
        if (m_data[i] != other.m_data[i]) {
            return false;
        }
    }

    return true;
}

template <typename T>
bool MyList_1<T>::operator!=(const MyList_1 &other) const {
    return !(*this == other);
}

template <typename T>
T &MyList_1<T>::operator[](const size_t index) {
    checkIndex(index, "operator[]");
    return m_data[index];
}

template <typename T>
void MyList_1<T>::print() const {
    Node *current = m_firstNode;
    size_t index = 0;

    std::cout << "=== List Contents ===" << std::endl;
    std::cout << " Size: " << m_size << std::endl;
    std::cout << "First: " << m_firstNode << std::endl;
    std::cout << " Last: " << m_lastNode << std::endl;
    std::cout << "---------------------" << std::endl;

    while (current != nullptr) {
        std::cout << "Node " << index++ << " " << current << ": data = " << current->data
                  << ", next = " << current->next << std::endl;
        current = current->next;
    }

    if (m_size == 0) {
        std::cout << "List is empty" << std::endl;
    }
}

template <typename T>
const T &MyList_1<T>::operator[](const size_t index) const {
    checkIndex(index, "operator[]");
    return m_data[index];
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const MyList_1<T> &myVector) {
    for (size_t i = 0; i < myVector.size(); ++i) {
        os << myVector.at(i) << " ";
    }
    return os;
}

template <typename T>
MyList_1<T>::~MyList_1() {
    delete[] m_data;
}

template <typename T>
void MyList_1<T>::push_back(const T &value) {
    if (m_size == m_capacity) {
        growCapacity();
    }
    m_data[m_size] = value;
    ++m_size;
}

template <typename T>
void MyList_1<T>::insert(const size_t index, const T &value) {
    if (index == m_size) {
        push_back(value);
        return;
    }
    checkIndex(index, "insert");
    if (m_size == m_capacity) {
        growCapacity();
    }
    std::copy_backward(m_data + index, m_data + m_size, m_data + m_size + 1);
    m_data[index] = value;
    ++m_size;
}

template <typename T>
void MyList_1<T>::erase(const size_t index) {
    checkIndex(index, "erase");
    std::move(m_data + index + 1, m_data + m_size, m_data + index);
    --m_size;
    m_data[m_size] = T();
}

template <typename T>
size_t MyList_1<T>::capacity() const {
    return m_capacity;
}

template <typename T>
size_t MyList_1<T>::size() const {
    return m_size;
}

template <typename T>
void MyList_1<T>::reserve(const size_t new_capacity) {
    if (new_capacity > m_capacity) {
        T *new_data = new T[new_capacity];
        std::copy(m_data, m_data + m_size, new_data);

        delete[] m_data;
        m_data = new_data;
        m_capacity = new_capacity;
    }
}

template <typename T>
void MyList_1<T>::copyFrom(const MyList_1 &other) {
   // Очистка текущего списка
    Node *current = m_firstNode;
    while (current != nullptr) {
        Node *nextNode = current->next;
        delete current;
        current = nextNode;
    }
    m_firstNode = nullptr;
    m_lastNode = nullptr;

    // Копирование из другого списка
    if (other.m_size > 0) {
        Node* it = other.m_firstNode;
        m_firstNode = new Node();
        m_firstNode->data = it->data;
        m_lastNode = m_firstNode;
        it = it->next;

        for (size_t i = 1; i < other.m_size; i++) {
            Node *newNode = new Node();
            newNode->data = it->data;
            m_lastNode->next = newNode;
            m_lastNode = newNode;
            it = it->next;
        }
        m_lastNode->next = nullptr;
        m_size = other.m_size;
    }
}

template <typename T>
void MyList_1<T>::checkIndex(const size_t index, const char *function_name) const {
    if (index >= m_size) {
        std::ostringstream oss;
        oss << "MyList_1::" << function_name << "(): index " << index
            << " out of range (size: " << m_size << ")";
        throw std::out_of_range(oss.str());
    }
}

template <typename T>
void MyList_1<T>::growCapacity() {
    size_t new_capacity = static_cast<size_t>(m_capacity * CAPACITY_FACTOR);
    // Гарантируем хотя бы минимальное увеличение
    if (new_capacity <= m_capacity) {
        new_capacity = m_capacity + 1;
    }
    reserve(new_capacity);
}

// Реализация методов iterator
template <typename T>
MyList_1<T>::iterator::iterator(T *ptr) : m_ptr(ptr) {}

template <typename T>
T &MyList_1<T>::iterator::operator*() const {
    return *m_ptr;
}

template <typename T>
T *MyList_1<T>::iterator::get() const {
    return m_ptr;
}

template <typename T>
typename MyList_1<T>::iterator &MyList_1<T>::iterator::operator++() {
    ++m_ptr;
    return *this;
}

template <typename T>
typename MyList_1<T>::iterator MyList_1<T>::iterator::operator++(int) {
    iterator temp = *this;
    ++m_ptr;
    return temp;
}

template <typename T>
bool MyList_1<T>::iterator::operator==(const iterator &other) const {
    return m_ptr == other.m_ptr;
}

template <typename T>
bool MyList_1<T>::iterator::operator!=(const iterator &other) const {
    return m_ptr != other.m_ptr;
}

// Реализация методов const_iterator
template <typename T>
MyList_1<T>::const_iterator::const_iterator(const T *ptr) : m_ptr(ptr) {}

template <typename T>
const T &MyList_1<T>::const_iterator::operator*() const {
    return *m_ptr;
}

template <typename T>
const T *MyList_1<T>::const_iterator::get() const {
    return m_ptr;
}

template <typename T>
typename MyList_1<T>::const_iterator &MyList_1<T>::const_iterator::operator++() {
    ++m_ptr;
    return *this;
}

template <typename T>
typename MyList_1<T>::const_iterator MyList_1<T>::const_iterator::operator++(int) {
    const_iterator temp = *this;
    ++m_ptr;
    return temp;
}

template <typename T>
bool MyList_1<T>::const_iterator::operator==(const const_iterator &other) const {
    return m_ptr == other.m_ptr;
}

template <typename T>
bool MyList_1<T>::const_iterator::operator!=(const const_iterator &other) const {
    return m_ptr != other.m_ptr;
}

// Реализация методов MyList_1 для итераторов
template <typename T>
typename MyList_1<T>::iterator MyList_1<T>::begin() noexcept {
    return iterator(m_data);
}

template <typename T>
typename MyList_1<T>::iterator MyList_1<T>::end() noexcept {
    return iterator(m_data + m_size);
}

template <typename T>
typename MyList_1<T>::const_iterator MyList_1<T>::begin() const noexcept {
    return const_iterator(m_data);
}

template <typename T>
typename MyList_1<T>::const_iterator MyList_1<T>::end() const noexcept {
    return const_iterator(m_data + m_size);
}
