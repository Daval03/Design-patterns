#include "Node.h"

template<class T>
T Node<T>::getData() {
    return this->data;
}

template<class T>
void Node<T>::setData(T data) {
    this->data = data;
}

template<class T>
Node<T> Node<T>::getNext() {
    return this->next;
}

template<class T>
void Node<T>::setNext(Node *next) {
    this->next=next;
}





