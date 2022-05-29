template<class T>
class Queue {
public:
    Queue();
    Queue(const Queue&); // Maybe won't need it
    ~Queue();
    Queue& operator=(const Queue& other);

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

private:
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
Queue<T>::Node::Node(const T& val): m_val(T), m_next(NULL) {}

template<class T>
class Queue<T>::Iterator {
    Queue<T>::Node *m_node;
    Iterator(Queue<T>::Node *begin);
    friend class Queue<T>::Node; //Might not need it

public:
    T& operator*();
    Iterator& operator++();
    bool operator!=(const Iterator& other) const;
};

template<class T>
T& Queue<T>::Iterator::operator*() {
    if (this->m_node == NULL) {
        // exception?
    }

    return this->m_node->m_val;
}

template<class T>
Iterator& Queue<T>::Iterator::operator++() {
    if (this->m_node == NULL) {
        // exception?
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
Queue<T>::Queue(): m_size(0), m_head(NULL), m_last(NULL) {}

template<class T>
void Queue<T>::pushBack(const T& element) {
    if (this->m_last == NULL) {
        this->m_head = new Queue<T>::Node(element);
        this->m_last = this->m_head;
    }

    this->m_last->m_next = new Queue<T>::Node(element);
    this->m_last = this->m_last->m_next;
    this->m_size++;
}

template<class T>
T& Queue<T>::front() {
    if (this->m_head == NULL) {
        // Raise exception
    }

    return this->m_head->m_val;
}

template<class T>
const T& Queue<T>::front() const{
    if (this->m_head == NULL) {
        // Raise exception
    }

    return this->m_head->m_val;
}

template<class T>
void Queue<T>::popFront() {
    if (this->m_head == NULL) {
        // Raise exception
        return;
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
Queue<T>::Iterator Queue<T>::begin() {
    return Queue<T>::Iterator(this->m_head);
}

template<class T>
Queue<T>::Iterator Queue<T>::end() {
    return Queue<T>::Iterator(NULL);
}

//TODO: Change this to const iterator
template<class T>
Queue<T> filter(const Queue<T>& originalQueue, bool (*predicat)(const T&)) {
    Queue<T> filteredQueue = Queue<T>();
    for (Queue<T>::Iterator elem = originalQueue.begin(); elem != originalQueue.end(), ++elem) {
        if (predicat(*elem)) {
            filteredQueue.pushBack(*elem);
        }
    }

    return filteredQueue;
}

template<class T>
Queue<T> transform(Queue<T>& queue, void (*modifier)(T&)) {
    for (Queue<T>::Iterator elem = queue.begin(); elem != queue.end(), ++elem) {
        modifier(*elem);
    }
}