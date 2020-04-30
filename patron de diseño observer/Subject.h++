//
// Created by aldo on 28/3/20.
//
#ifndef DATOS_2___2_0_SUBJECT_H
#define DATOS_2___2_0_SUBJECT_H
#include "Observer.h++"
class Subject{
public:
    virtual void notify()=0;
    virtual void Attach(Observer *obs)=0;
    virtual void Detach(Observer *obs)=0;
};
#endif //DATOS_2___2_0_SUBJECT_H