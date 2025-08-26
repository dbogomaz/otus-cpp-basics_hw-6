// @file: myvector.ipp

#include <sstream>
#include <stdexcept>

#include "mylist_1.h"

// --- Конструкторы и оператор присваивания ---

// Конструктор по умолчанию и с параметром размера
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

// Конструктор инициализации
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

// Конструктор копирования
template <typename T>
MyList_1<T>::MyList_1(const MyList_1 &other) {
    copyFrom(other);
}

// Конструктор перемещения
template <typename T>
MyList_1<T>::MyList_1(MyList_1 &&other) noexcept {
    moveFrom(std::move(other));
}

// Оператор присваивания копированием
template <typename T>
MyList_1<T> &MyList_1<T>::operator=(const MyList_1 &other) {
    if (this != &other) {
        clear();
        copyFrom(other);
    }
    return *this;
}

// Оператор присваивания перемещением
template <typename T>
MyList_1<T> &MyList_1<T>::operator=(MyList_1 &&other) noexcept {
    if (this != &other) {
        clear();
        moveFrom(std::move(other));
    }
    return *this;
}

// Операторы сравнения
template <typename T>
bool MyList_1<T>::operator==(const MyList_1 &other) const {
    if (m_size != other.m_size) {
        return false;
    }
    Node *a = m_firstNode;
    Node *b = other.m_firstNode;
    while (a && b) {
        if (a->data != b->data) return false;
        a = a->next;
        b = b->next;
    }
    return true;
}

template <typename T>
bool MyList_1<T>::operator!=(const MyList_1 &other) const {
    return !(*this == other);
}

// Деструктор
template <typename T>
MyList_1<T>::~MyList_1() {
    clear();
}

// --- Методы изменения списка ---

template <typename T>
void MyList_1<T>::push_back(const T &value) {
    Node *newNode = new Node();
    newNode->data = value;
    if (m_size == 0) {
        m_firstNode = newNode;
        m_lastNode = newNode;
    } else {
        m_lastNode->next = newNode;
        m_lastNode = newNode;
    }
    ++m_size;
}

template <typename T>
void MyList_1<T>::insert(const size_t index, const T &value) {
    checkIndex(index, "insert");
    Node *newNode = new Node();
    newNode->data = value;
    if (index == 0) {
        newNode->next = m_firstNode;
        m_firstNode = newNode;
        if (m_size == 0) m_lastNode = newNode;
    } else {
        Node *prev = m_firstNode;
        for (size_t i = 0; i < index - 1; ++i) prev = prev->next;
        newNode->next = prev->next;
        prev->next = newNode;
        if (newNode->next == nullptr) m_lastNode = newNode;
    }
    ++m_size;
}

template <typename T>
void MyList_1<T>::erase(const size_t index) {
    checkIndex(index, "erase");
    Node *toDelete = nullptr;
    if (index == 0) {
        toDelete = m_firstNode;
        m_firstNode = m_firstNode->next;
        if (m_firstNode == nullptr) m_lastNode = nullptr;
    } else {
        Node *prev = m_firstNode;
        for (size_t i = 0; i < index - 1; ++i) prev = prev->next;
        toDelete = prev->next;
        prev->next = toDelete->next;
        if (prev->next == nullptr) m_lastNode = prev;
    }
    delete toDelete;
    --m_size;
}

template <typename T>
void MyList_1<T>::clear() {
    Node *current = m_firstNode;
    while (current != nullptr) {
        Node *nextNode = current->next;
        delete current;
        current = nextNode;
    }
    m_firstNode = nullptr;
    m_lastNode = nullptr;
    m_size = 0;
}

// --- Методы информации о списке ---

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
        m_capacity = new_capacity;
    }
}

// --- Методы доступа к элементам ---

template <typename T>
T &MyList_1<T>::at(const size_t index) {
    checkIndex(index, "at");
    Node *current = m_firstNode;
    for (size_t i = 0; i < index; ++i) current = current->next;
    return current->data;
}

template <typename T>
const T &MyList_1<T>::at(size_t index) const {
    checkIndex(index, "at");
    Node *current = m_firstNode;
    for (size_t i = 0; i < index; ++i) current = current->next;
    return current->data;
}

template <typename T>
T &MyList_1<T>::operator[](const size_t index) {
    return at(index);
}

template <typename T>
const T &MyList_1<T>::operator[](const size_t index) const {
    return at(index);
}

// --- Итераторы ---

template <typename T>
typename MyList_1<T>::iterator MyList_1<T>::begin() noexcept {
    return iterator(m_firstNode ? &m_firstNode->data : nullptr);
}

template <typename T>
typename MyList_1<T>::iterator MyList_1<T>::end() noexcept {
    return iterator(nullptr);
}

template <typename T>
typename MyList_1<T>::const_iterator MyList_1<T>::begin() const noexcept {
    return const_iterator(m_firstNode ? &m_firstNode->data : nullptr);
}

template <typename T>
typename MyList_1<T>::const_iterator MyList_1<T>::end() const noexcept {
    return const_iterator(nullptr);
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

// --- Приватные методы ---

template <typename T>
void MyList_1<T>::copyFrom(const MyList_1 &other) {
    clear();
    if (other.m_size > 0) {
        Node *it = other.m_firstNode;
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
void MyList_1<T>::moveFrom(MyList_1 &&other) noexcept {
    clear();
    m_size = other.m_size;
    m_firstNode = other.m_firstNode;
    m_lastNode = other.m_lastNode;
    other.m_size = 0;
    other.m_firstNode = nullptr;
    other.m_lastNode = nullptr;
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
    if (new_capacity <= m_capacity) {
        new_capacity = m_capacity + 1;
    }
    reserve(new_capacity);
}

// --- Реализация методов iterator ---

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

// --- Реализация методов const_iterator ---

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

template <typename T>
std::ostream &operator<<(std::ostream &os, const MyList_1<T> &myList) {
    for (const auto& item : myList) {
        os << item << " ";
    }
    return os;
}
