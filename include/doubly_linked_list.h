#pragma once

#include <cstddef>
#include <stdexcept>
#include <utility>
#include <vector>

template <typename T>
struct DNode {
    T value;
    DNode* prev;
    DNode* next;

    explicit DNode(const T& v, DNode* p = nullptr, DNode* n = nullptr)
        : value(v), prev(p), next(n) {}
};

template <typename T>
class DLinkedList {
public:
    DLinkedList();
    ~DLinkedList();
    DLinkedList(const DLinkedList& other);
    DLinkedList& operator=(const DLinkedList& other);

    void push_front(const T& value);
    void push_back(const T& value);
    bool pop_front();
    bool pop_back();

    T& front();
    const T& front() const;
    T& back();
    const T& back() const;
    std::size_t size() const noexcept;
    bool empty() const noexcept;
    bool contains(const T& value) const;
    std::vector<T> to_vector() const;
    void clear();

private:
    DNode<T>* header_;
    DNode<T>* trailer_;
    std::size_t size_;
};

template <typename T>
DLinkedList<T>::DLinkedList() : size_(0) {
    header_ = new DNode<T>(T(), nullptr, nullptr);
    trailer_ = new DNode<T>(T(), nullptr, nullptr);
    header_->next = trailer_;
    trailer_->prev = header_;
}

//TODO: Implement the destructor, copy constructor, assignment operator, and other member functions for the DLinkedList class.
template <typename T>
DLinkedList<T>::~DLinkedList() {
    clear();
    delete header_;
    delete trailer_;
}

//TODO: Implement the copy constructor for the DLinkedList class.
template <typename T>
DLinkedList<T>::DLinkedList(const DLinkedList& other) : size_(0) {
    if (other.empty())
    {
        return;
    }

    DNode<T>* current = other.header_->next;
    this->header_ = new DNode<T>(T(), nullptr, nullptr);
    this->trailer_ = new DNode<T>(T(), nullptr, nullptr);

    current = current->next;
    while (current != other.trailer_)
    {
        push_back(current->value);
        current = current->next;
    }
}

// TODO: Implement the assignment operator for the DLinkedList class.
template <typename T>
DLinkedList<T>& DLinkedList<T>::operator=(const DLinkedList& other) {

}

//TODO: Implement the push_front function for the DLinkedList class.
template <typename T>
void DLinkedList<T>::push_front(const T& value) {

}

//TODO: Implement the push_back function for the DLinkedList class.
template <typename T>
void DLinkedList<T>::push_back(const T& value) {
    DNode<T>* newNode = new DNode<T>(value, trailer_->prev, trailer_);
    if (trailer_->prev != nullptr)
    {
        trailer_->prev->next = newNode;
    }
    else
    {
        header_->next = newNode;
    }

}


//TODO: Implement the pop_front function for the DLinkedList class.
template <typename T>
bool DLinkedList<T>::pop_front() {
    if (empty())
    {
        return false;
    }

    DNode<T>* temp = header_->next;
    header_->next = temp->next;
    if (temp->next != nullptr)
    {
        temp->next->prev = header_;
    }
    else
    {
        trailer_->prev = header_;
    }
    delete temp;
    return true;
}

//TODO: Implement the pop_back function for the DLinkedList class.
template <typename T>
bool DLinkedList<T>::pop_back() {
    if (empty())
    {
        return false;
    }

    DNode<T>* temp = trailer_->prev;
    trailer_->prev = temp->prev;
    if (temp->prev != nullptr)
    {
        temp->prev->next = trailer_;
    }
    else
    {
        header_->next = trailer_;
    }
    delete temp;
    return true;
}

//TODO: Implement the front function for the DLinkedList class
template <typename T>
T& DLinkedList<T>::front() {
if (empty())
{
    throw std::out_of_range("DLinkedList is empty");
}
DNode<T>* firstNode = header_->next;
return firstNode->value;
}

template <typename T>
const T& DLinkedList<T>::front() const {
//TODO: Implement the const version of the front function for the DLinkedList class
if (empty())
{
    throw std::out_of_range("DLinkedList is empty");
}
const T& firstNode = header_->next;
return firstNode->value;
}

template <typename T>
T& DLinkedList<T>::back() {
//TODO: Implement the back function for the DLinkedList class
if (empty())
{
    throw std::out_of_range("DLinkedList is empty");
}
DNode<T>* lastNode = trailer_->prev;
return lastNode->value;
}

template <typename T>
const T& DLinkedList<T>::back() const {
//TODO: Implement the const version of the back function for the DLinkedList class
if (empty())
{
    throw std::out_of_range("DLinkedList is empty");
}
const T& lastNode = trailer_->prev;
return lastNode->value;
}

template <typename T>
std::size_t DLinkedList<T>::size() const noexcept {
//TODO: Implement the size function for the DLinkedList class
return size_;
}

template <typename T>
bool DLinkedList<T>::empty() const noexcept {
//TODO: Implement the empty function for the DLinkedList class
if (header_->next == trailer_)
{
    return true;
}
return false;
}

template <typename T>
bool DLinkedList<T>::contains(const T& value) const {
//TODO: Implement the contains function for the DLinkedList class
DNode<T>* current = header_->next;
while (current != trailer_)
{
    if (current->value == value)
    {
        return true;
    }
    current = current->next;
}
return false;
}

template <typename T>
std::vector<T> DLinkedList<T>::to_vector() const {
// TODO: Implement the to_vector function for the DLinkedList class
std::vector<T> vec;
DNode<T>* current = header_->next;
while (current != trailer_)
{
    vec.push_back(current->value);
    current = current->next;
}
return vec;
}

template <typename T>
void DLinkedList<T>::clear() {
// TODO: Implement the clear function for the DLinkedList class
while (!empty())
{
    pop_front();
}
}
