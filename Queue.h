#ifndef EX3_Queue_H
#define EX3_Queue_H

#include <assert.h>

template<class T>
class Queue {
public:
    Queue();
    Queue(const Queue<T>&);
    ~Queue();
    Queue& operator=(const Queue<T>& other);

    void pushBack(const T& element);
    T& front();
    const T& front() const;
    void popFront();
    int size() const;

    class Iterator;
    Iterator begin();
    Iterator end();

    class ConstIterator;
    ConstIterator begin() const;
    ConstIterator end() const;

    class Node;
    class EmptyQueue {};

private:
    void clear();
    void copyNodes(const Queue& other);

    int m_size;
    Node *m_head;
    Node *m_last;
};

template<class T>
class Queue<T>::Node {
public:
    Node(const T& val);
    Node(const Node&) = default; // Maybe won't need it
    ~Node() = default;
    Node& operator=(const Node& other) = default;

    T m_val;
    Node *m_next;
};

template<class T>
Queue<T>::Node::Node(const T& val): m_val(val), m_next(nullptr) {}

template<class T>
class Queue<T>::Iterator {
    Queue<T>::Node *m_node;

public:
    T& operator*() const;
    Iterator& operator++();
    bool operator!=(const Iterator& other) const;
    Iterator(Queue<T>::Node *begin);
    Iterator(const Queue<T>::Iterator& other) = default;
    Iterator& operator=(const Queue<T>::Iterator& other) = default;
    ~Iterator() = default;
    class InvalidOperation {};
};

template<class T>
T& Queue<T>::Iterator::operator*() const {
    if (this->m_node == nullptr) {
        throw InvalidOperation();
    }

    return this->m_node->m_val;
}

template<class T>
typename Queue<T>::Iterator& Queue<T>::Iterator::operator++() {
    if (this->m_node == nullptr) {
        throw InvalidOperation();
    }

    this->m_node = this->m_node->m_next;
    return *this;
}

template<class T>
bool Queue<T>::Iterator::operator!=(const Iterator& other) const {
    return this->m_node != other.m_node;
}

template<class T>
Queue<T>::Iterator::Iterator(Queue<T>::Node *begin): m_node(begin) {}

template<class T>
class Queue<T>::ConstIterator {
    Queue<T>::Node const *m_node;

public:
    const T& operator*() const;
    ConstIterator& operator++();
    bool operator!=(const ConstIterator& other) const;
    ConstIterator(Queue<T>::Node const *begin);
    ConstIterator(const Queue<T>::ConstIterator& other) = default;
    ConstIterator& operator=(const Queue<T>::ConstIterator& other) = default;
    ~ConstIterator() = default;
    class InvalidOperation {};
};

template<class T>
const T& Queue<T>::ConstIterator::operator*() const {
    if (this->m_node == nullptr) {
        throw InvalidOperation();
    }

    return this->m_node->m_val;
}

template<class T>
typename Queue<T>::ConstIterator& Queue<T>::ConstIterator::operator++() {
    if (this->m_node == nullptr) {
        throw InvalidOperation();
    }
    this->m_node = this->m_node->m_next;
    return *this;
}

template<class T>
bool Queue<T>::ConstIterator::operator!=(const ConstIterator& other) const {
    return this->m_node != other.m_node;
}

template<class T>
Queue<T>::ConstIterator::ConstIterator(Queue<T>::Node const *begin): m_node(begin) {}


template<class T>
Queue<T>::Queue(): m_size(0), m_head(nullptr), m_last(nullptr) {}

template<class T>
Queue<T>::Queue(const Queue<T>& other): m_size(0), m_head(nullptr), m_last(nullptr) {
    copyNodes(other);
}

template<class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other) {
    if (this == &other) {
        return *this;
    }

    clear();
    copyNodes(other);
    return *this;
}

template<class T>
void Queue<T>::pushBack(const T& element) {
    if (this->m_last == nullptr) {
        this->m_head = new Queue<T>::Node(element);
        this->m_last = this->m_head;
    } else {
        this->m_last->m_next = new Queue<T>::Node(element);
        this->m_last = this->m_last->m_next;
    }
    this->m_size++;
}

template<class T>
T& Queue<T>::front() {
    if (this->m_head == nullptr) {
        throw EmptyQueue();
    }

    return this->m_head->m_val;
}

template<class T>
const T& Queue<T>::front() const{
    if (this->m_head == nullptr) {
        throw EmptyQueue();
    }

    return this->m_head->m_val;
}

template<class T>
void Queue<T>::popFront() {
    if (this->m_head == nullptr) {
        throw EmptyQueue();
    }

    Node *newHead = m_head->m_next;
    delete this->m_head;
    this->m_head = newHead;
    this->m_size--;
}

template<class T>
int Queue<T>::size() const {
    return this->m_size;
}

template<class T>
typename Queue<T>::Iterator Queue<T>::begin() {
    return Queue<T>::Iterator(this->m_head);
}

template<class T>
typename Queue<T>::Iterator Queue<T>::end() {
    return Queue<T>::Iterator(nullptr);
}

template<class T>
typename Queue<T>::ConstIterator Queue<T>::begin() const {
    return Queue<T>::ConstIterator(this->m_head);
}

template<class T>
typename Queue<T>::ConstIterator Queue<T>::end() const {
    return Queue<T>::ConstIterator(nullptr);
}

template<class T>
void Queue<T>::clear() {
    Node *next = nullptr;
    while (nullptr != this->m_head) {
        next = this->m_head->m_next;
        delete m_head;
        m_size--;
        m_head = next;
    }

    // Finished clear, meaning now m_last points to a deleted node
    this->m_last = nullptr;
}

template<class T>
void Queue<T>::copyNodes(const Queue& other) {
    for (const T& elem : other) {
        pushBack(elem);
    }
}

template<class T>
Queue<T>::~Queue() {
    clear();
}

template<class T>
Queue<T> filter(const Queue<T>& original, bool (*predicat)(T)) {
    assert(predicat);
    Queue<T> filtered = Queue<T>();
    if (!predicat) {
        return filtered;
    }

    for (const T& elem : original) {
        if (predicat(elem)) {
            filtered.pushBack(elem);
        }
    }

    return filtered;
}

template<class T>
void transform(Queue<T>& queue, void (*modifier)(T&)) {
    assert(modifier);
    if (!modifier) {
        return;
    }

    for (T& elem : queue) {
        modifier(elem);
    }
}

#endif //EX3_Queue_H