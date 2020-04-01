//
// Created by aldo on 25/2/20.
//

#ifndef DATOS_2___2_0_LISTA_H
#define DATOS_2___2_0_LISTA_H
#include <iostream>
#include "string"
using namespace std;
struct nodo{
    string dato;
    nodo *next;
};
class lista {
private:
    int size;
    nodo *first;
    nodo *last;
public:
    void addlista(string dato);
    lista(string dato);
    lista();
    string findDato(int posicion);
};


#endif //DATOS_2___2_0_LISTA_H
