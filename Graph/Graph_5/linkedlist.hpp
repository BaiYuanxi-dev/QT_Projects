#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>

template<class T>
class pNode;


template<class T>
class LinkedList
{
    friend LinkedList<int>* linkTwoLists(LinkedList<int>* list1, LinkedList<int>* list2);
public:
    //create LinkedList
    LinkedList();

    //delete LinkedList
    ~LinkedList();

    //return length of LinkedList
    int length();

    //get position of the special element "e"
    int LocateElem(const T& e) const;

    //get element according to index and return the element into the "e" variable
    bool getElement(int index, T& e) const;

    //delete element according to index and return that node
    LinkedList<T>& del(int index, T& e);

    //insert the element "e" into index "index",
    LinkedList<T>& insert(int index, const T& e);

    //output the whole LinkedList
    void output();
private:
    pNode<T>* head;
};

//node class
template<class T>
class pNode {
    friend LinkedList<T>;
    friend LinkedList<int>* linkTwoLists(LinkedList<int>* list1, LinkedList<int>* list2);
private:
    T data;
    pNode<T>* next;
};




//create empty LinkedList
template <class T>
LinkedList<T>::LinkedList() {
    this->head = nullptr;
}

//delete LinkedList
template <class T>
LinkedList<T>::~LinkedList() {
    pNode<T>* p = head;

    while (p != nullptr) {
        head = head->next;
        delete p;
        p = head;
    }
}

//return length of LinkedList
template <class T>
int LinkedList<T>::length() {
    int length = 0;
    pNode<T>* p = head;

    while (p != nullptr) {
        length++;
        p = p->next;
    }
    return length;
}

//get position of the special element "e"
template <class T>
int LinkedList<T>::LocateElem(const T& e) const {
    int index = 1;
    pNode<T>* p = head;

    while (p != nullptr && p->data != e) {
        p = p->next;
        index++;
    }
    if (p != nullptr) {
        return index;
    }
    else {
        throw "without this element";
        //return 0;
    }

}

//get element according to index and return the element into the "e" variable
template <class T>
bool LinkedList<T>::getElement(int index, T& e) const {

    pNode<T>* p = head;

    if (index < 1) {
        //return false;
        throw "-1" ;
    }
    int i = 1;
    while (p != nullptr) {
        if (i == index) {
            break;
        }
        p = p->next;
        i++;
    }
    if (p != nullptr) {
        e = p->data;
        return true;
    }
    else {
        return false;
    }
}

//insert the element "e" into index element(before the index)
template <class T>
LinkedList<T>& LinkedList<T>::insert(int index, const T& e) {
    pNode<T>* p = head;
    pNode<T>* newNode = new pNode<T>;
    newNode->data = e;

    if (index <= 0) {
        return *this;
    }

    if (index == 1) {
        newNode->next = head;
        head = newNode;
    }
    else {
        for (int i = 1; i < index - 1 && p != nullptr; i++) {
            p = p->next;
        }
        if (index > 0 && p == nullptr) {
            return *this;
        }
        else {
            newNode->next = p->next;
            p->next = newNode;
        }

    }

    return *this;

}

//delete element according to index and return that node
template<class T>
LinkedList<T>& LinkedList<T>::del(int index, T& e) {
    pNode<T>* p = head;

    if (index < 1 || p == nullptr) {
        return *this;
    }

    if (index == 1) {
        head = head->next;
        //e = p->data;
        //delete p;
    }
    else {
        pNode<T>* q = head;
        for (int i = 1; i < index - 1 && p != nullptr; i++) {
            q = q->next;
        }
        if (q == nullptr || q->next == nullptr) {
            //out of bounds
            //return *this;
            throw "out of bounds";
        }

        p = q->next;
        q->next = p->next;
    }
    e = p->data;
    delete p;
    return *this;
}


//output the whole linkList
template <class T>
void LinkedList<T>::output() {
    pNode<T>* p = head;
    std::cout << "{";
    while (p != nullptr) {
        if (p->next != nullptr) {
            std::cout << p->data << ", ";
        }
        else {
            std::cout << p->data;
        }

        p = p->next;
    }
    std::cout << "}" <<std::endl;
}

#endif // LINKEDLIST_H


