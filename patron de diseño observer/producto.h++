//
// Created by aldo on 28/3/20.
//

#ifndef DATOS_2___2_0_PRODUCTO_H
#define DATOS_2___2_0_PRODUCTO_H
#include <iostream>
#include <string>
#include "Observer.h++"
using namespace std;
class producto: public Observer{
    string nombre;
public:
    producto(string nombre);
    virtual void update(int price) override;
};

#endif //DATOS_2___2_0_PRODUCTO_H
