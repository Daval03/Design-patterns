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
    int length=0;

public:
    LinkedList<T>() {
        first = NULL;
        last = NULL;
        length = 0;
    }

    bool isEmpty();
    void add(T data);
    T operator[](int index);
    void removeByName(int key);
    T get(int index);
    void print();
    int size();

private:

};




#endif //DATOS_2___2_0_LINKEDLIST_H
