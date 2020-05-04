#ifndef DATOS_2___2_0_LINKEDLIST_H
#define DATOS_2___2_0_LINKEDLIST_H

#include <iostream>
#include "Node.h"
using namespace std;

template <class T>
class LinkedList {
    Node<T> *first, *last;

public:
    LinkedList(){
        first,last = NULL;
    }

    bool isEmpty();
    void addLast(T data);
    T get(int index);
    T operator[](int index);

};



#endif //DATOS_2___2_0_LINKEDLIST_H
