#ifndef QUEUE_HPP
#define QUEUE_HPP

template <class T>
class Node;

//queue Data Structure
template<class T>
class Queue {
public:
    //constructor
    Queue() { front = nullptr; rear = nullptr; };

    //destructor
    ~Queue();

    //judge if the queue is empty;
    bool isEmpty() { return front == nullptr; };

    //get first node of queue
    T getFirst() const;

    //get last node of queue
    T getLast() const;

    //add a new node at the end
    Queue<T>& add(const T& t);

    //delete a node at head point
    Queue<T>& del(T& t);
private:
    Node<T>* front;
    Node<T>* rear;
};

template<class T>
class Node {
    friend class Queue<T>;
private:
    T data;
    Node<T>* next;
};

template<class T>
Queue<T>:: ~Queue() {
    Node<T>* p = front;

    while (front != nullptr) {
        front = front->next;
        free(p);
        p = front;
    }
}

//get first node of queue
template<class T>
T Queue<T>::getFirst() const {
    Node<T> *p = front;
    if (p != nullptr) {
        return p->data;
    }
    else {
        throw "stack empty";
    }
}

//get last node of queue
template<class T>
T Queue<T>::getLast() const {
    Node<T>* p = rear;
    if (rear != nullptr) {
        return p->data;
    }
    else {
        throw "stack empty";
    }
}

//add a new node at the end
template<class T>
Queue<T>& Queue<T>::add(const T& t) {
    Node<T>* newNode = new Node<T>;

    newNode->data = t;
    newNode->next = nullptr;

    if (front == nullptr) {
        front = newNode;
    }
    else {
        rear->next = newNode;
    }
    rear = newNode;
    return *this;
}

//delete a node at head point
template<class T>
Queue<T>& Queue<T>::del(T& t) {
    Node<T>* p = front;
    if (front == nullptr) {
        throw"stack empty";
    }
    t = p->data;
    front = front->next;
    delete p;
    return *this;
}



#endif // QUEUE_HPP
