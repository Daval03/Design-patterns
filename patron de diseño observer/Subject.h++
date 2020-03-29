//
// Created by aldo on 28/3/20.
//

#include "Observer.h++"
#ifndef DATOS_2___2_0_SUBJECT_H
#define DATOS_2___2_0_SUBJECT_H
#endif //DATOS_2___2_0_SUBJECT_H
class Subject{
public:
    virtual void notify()=0;
    virtual void Attach(Observer *obs)=0;
    virtual void Detach(Observer *obs)=0;
};