//
// Created by aldo on 31/3/20.
//

#ifndef DATOS_2___2_0_SMARTPTR_H
#define DATOS_2___2_0_SMARTPTR_H

#include<iostream>
using namespace std;
template <class T>
class SmartPtr {
    T *ptr;
public:
//    explicit SmartPtr(T *p = NULL);
//    ~SmartPtr();
//    T & operator * ();
//    T * operator -> ();
    explicit SmartPtr(T *p = NULL) { ptr = p; }
    ~SmartPtr() { delete(ptr); }
    T & operator * () {  return *ptr; }
    T * operator -> () { return ptr; }
    T& operator =(const T &valor);
};


#endif //DATOS_2___2_0_SMARTPTR_H
