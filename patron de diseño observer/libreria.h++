//
// Created by aldo on 28/3/20.
//
#ifndef DATOS_2___2_0_LIBRERIA_H
#define DATOS_2___2_0_LIBRERIA_H
#include <vector>
#include <algorithm>
#include <iostream>
#include "Subject.h++"
#include "producto.h++"

class libreria: public Subject{
    std::vector<Observer *> observers;
    int price;
public:
    void notify() override;
    void Attach(Observer *obs) override;
    void Detach(Observer *obs) override;
    void setState(int price);
};


#endif //DATOS_2___2_0_LIBRERIA_H
