#include "LinkedList.h"

//check if our list is currently empty
template<class T>
bool LinkedList<T>::isEmpty() {
    return (first==NULL);
}

template<class T>
void LinkedList<T>::addLast(T data) {
    if(isEmpty()) { //if empty
        first->setData(data);
        last = first;
    }
    else {
        // The list isn't empty
        if(last == first) {
            // The list has one element
            last = new Node<T>;
            last->setData(data);
            last->setNext(NULL);
            first->setNext(last);
        } else {
            // The list has more than one element
            auto* insdata = new Node<T>;
            insdata->setData(data);
            insdata->setNext(NULL);
            last->setNext(insdata);
            last = insdata;
        }
    }
}

template<class T>
T LinkedList<T>::get(int index) {
    if(isEmpty()) {
        return NULL;
    }
    if(index == 0) {
        // Get the first element
        return this->first->getData();
    } else {
        // Get the index'th element
        Node<T>* curr = this->first;
        for(int i=0; i < index; ++i) {
            curr = curr->getNext();
        }
        return curr->getData();
    }
}

template<class T>
T LinkedList<T>::operator [](int index){
        return get(index);
}








