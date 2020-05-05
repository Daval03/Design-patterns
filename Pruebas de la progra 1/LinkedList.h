#ifndef DATOS_2___2_0_LINKEDLIST_H
#define DATOS_2___2_0_LINKEDLIST_H

#include <iostream>

using namespace std;

template<class T>
struct node {
    node<T>* next;
    T data;
};

template<class T>
class LinkedList
{
    node<T>* first;
    node<T>* last;

public:
    LinkedList<T>() {
        first = NULL;
        last = NULL;
    }

    bool isEmpty();
    void add(T data);
    T operator[](int index);

private:
    T get(int index);

};




#endif //DATOS_2___2_0_LINKEDLIST_H
