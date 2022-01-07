#ifndef STACK_HPP
#define STACK_HPP

#include<string>
using namespace std;
template<class T>
class Node;

//stack ADT
template<class T>
class LinkedStack {
    //get priority of operator
    friend int getPriority(LinkedStack<string>& stack, const string op);
public:
    //create linked stack
    LinkedStack() { top = nullptr; };

    //delete linked stack
    ~LinkedStack();

    //judge if the stack is empty
    bool IsEmpty() const { return top == nullptr; };

    //get top element of stack
    T getTop();

    //push element into stack
    LinkedStack<T>& push(const T& e);

    //pop element out of stack
    LinkedStack<T>& pop(T& e);

private:
    Node<T> *top;
};



//Node class
template<class T>
class Node {
    friend LinkedStack<T>;
private:
    T data;
    Node<T>* next;
};

//delete all nodes
template<class T>
LinkedStack<T>::~LinkedStack() {
    Node<T>* p;
    while (top != nullptr) {
        p = top->next;
        delete top;
        top = p;
    }
}

//get top element of stack
template<class T>
T LinkedStack<T>::getTop() {
    T t;
    if (top != nullptr) {
        t = top->data;
    }
    else {
        throw "Stack is empty";
    }
    return t;
}

//push element into stack
template<class T>
LinkedStack<T>& LinkedStack<T>::push(const T& e) {
    Node<T>* newNode = new Node<T>;
    newNode->data = e;
    newNode->next = top;
    top = newNode;

    return *this;
}

//pop element out of stack
template<class T>
LinkedStack<T>& LinkedStack<T>::pop(T& e) {
    if (top == nullptr) {
        throw "Stack is empty";
    }
    else {
        Node<T>* p = top;
        top = top->next;
        e = p->data;
        delete p;
    }
    return *this;
}

#endif // STACK_HPP
