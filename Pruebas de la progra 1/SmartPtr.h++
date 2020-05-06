#ifndef DATOS_2___2_0_SMARTPTR_H
#define DATOS_2___2_0_SMARTPTR_H
#include<iostream>
#include "Gen_id.h++"
using namespace std;
template <class T>
class SmartPtr{
private:
    Gen_id GID;
    int id=GID.Generate_id();
    T *ptr;
public:
    explicit SmartPtr(T *p = NULL) { ptr = p; }
    ~SmartPtr() { delete(ptr); }
    T & operator * () {  return *ptr; }
    T * operator -> () { return ptr; }
    SmartPtr operator =(SmartPtr *obj){
        ptr=obj;
    }

    int getID(){
        return id;
    }
};



#endif //DATOS_2___2_0_SMARTPTR_H
