#pragma once

#include <cstddef>
#include <stdexcept>
#include <utility>
#include <vector>

template <typename T>
struct SNode {
    T value;
    SNode* next;

    explicit SNode(const T& v, SNode* n = nullptr) : value(v), next(n) {}
};

template <typename T>
class SLinkedList {
public:
    SLinkedList();
    ~SLinkedList();
    SLinkedList(const SLinkedList& other);
    SLinkedList& operator=(const SLinkedList& other);

    void push_front(const T& value);
    void push_back(const T& value);
    bool pop_front();
    bool pop_back();

    T& front();
    const T& front() const;
    std::size_t size() const noexcept;
    bool empty() const noexcept;
    bool contains(const T& value) const;
    std::vector<T> to_vector() const;
    void clear();

private:
    SNode<T>* head_;
    std::size_t size_;
};

template <typename T>
SLinkedList<T>::SLinkedList() : head_(nullptr), size_(0) {}

template <typename T>
SLinkedList<T>::~SLinkedList() {
//TODO: Implement the destructor for the SLinkedList class
SNode<T>* current = head_;
    while (current != nullptr)
    {
        SNode<T>* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

template <typename T>
SLinkedList<T>::SLinkedList(const SLinkedList& other) : head_(nullptr), size_(0) {
//TODO: Implement the copy constructor for the SLinkedList class
if (other.head_ == nullptr) 
{
        return;
}

    head_ = new SNode<T>(other.head_->value);
    SNode<T>* currentOther = other.head_->next;
    SNode<T>* currentThis = head_;

    while (currentOther != nullptr) 
    {
        currentThis->next = new SNode<T>(currentOther->value);
        currentThis = currentThis->next;
        currentOther = currentOther->next;
    }

    size_ = other.size_;
}

template <typename T>
SLinkedList<T>& SLinkedList<T>::operator=(const SLinkedList& other) {
//TODO: Implement the assignment operator for the SLinkedList class
    if (this == &other)
    {
        return *this;
    }
}

template <typename T>
void SLinkedList<T>::push_front(const T& value) {
// TODO: Implement the push_front function for the SLinkedList class
SNode<T>* newNode = new SNode<T>(value, head_);
    newNode->next = head_;
    head_ = newNode;
    ++size_;
}

template <typename T>
void SLinkedList<T>::push_back(const T& value) {
// TODO: Implement the push_back function for the SLinkedList class
SNode<T>* newNode = new SNode<T>(value);
if (head_ == nullptr)
{
    head_ = newNode;
    return;
}
SNode<T>* current = head_;
while (current->next != nullptr)
{
    current = current->next;
}
current->next = newNode;
}

template <typename T>
bool SLinkedList<T>::pop_front() {
// TODO: Implement the pop_front function for the SLinkedList class
    if(head_ == nullptr)
    {
        return false;
    }
    SNode<T>* temp = head_;
    head_ = head_->next;
    delete temp;
    return true;
}

template <typename T>
bool SLinkedList<T>::pop_back() {
// TODO: Implement the pop_back function for the SLinkedList class
if (head_ == nullptr)
{
    return false;
}

SNode<T>* temp = head_;
if (head_->next == nullptr)
{
    delete head_;
    head_ = nullptr;
    return true;
}

while (temp->next->next != nullptr)
{
    temp = temp->next;
}
delete temp->next;
temp->next = nullptr;
return true;
}


template <typename T>
T& SLinkedList<T>::front() {
// TODO: Implement the front function for the SLinkedList class
if (empty())
{
    throw std::out_of_range("SLinkedList is empty");
}
return head_->value;
}

template <typename T>
const T& SLinkedList<T>::front() const {
    if (empty()) {
        throw std::out_of_range("SLinkedList is empty");
    }
    return head_->value;
}

template <typename T>
std::size_t SLinkedList<T>::size() const noexcept {
// TODO: Implement the size function for the SLinkedList class
    return size_;
}

template <typename T>
bool SLinkedList<T>::empty() const noexcept {
// TODO: Implement the empty function for the SLinkedList class
if (head_ == nullptr)
{
    return true;
}
return false;

}

template <typename T>
bool SLinkedList<T>::contains(const T& value) const {
// TODO: Implement the contains function for the SLinkedList class
SNode<T>* current = head_;
while (current != nullptr)
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
std::vector<T> SLinkedList<T>::to_vector() const {
    std::vector<T> values;
    values.reserve(size_);
    for (SNode<T>* current = head_; current != nullptr; current = current->next) {
        values.push_back(current->value);
    }
    return values;
}

template <typename T>
void SLinkedList<T>::clear() {
//TODO: Implement the clear function for the SLinkedList class
    while (!empty())
    {
        pop_front();
    }
}
