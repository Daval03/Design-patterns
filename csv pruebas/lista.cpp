//
// Created by aldo on 25/2/20.
//
#include "lista.h"
lista::lista(string dato) {
    nodo *temp=new nodo;
    temp->dato=dato;
    temp->next= nullptr;
    first=temp;
    last=temp;
    size++;
}
lista::lista() {
    first= nullptr;
    last= nullptr;
}
void lista::addlista(string dato){
    nodo *temp=new nodo;
    temp->dato=dato;
    temp->next= nullptr;
    if(first==nullptr){
        first=temp;
        last=temp;
    }else{
        last->next=temp;
        last=temp;
    }size++;
}
string lista::findDato(int posicion) {
    nodo *temp=new nodo;
    temp=first;
    for(int i=0;i<size;i++){
        if(i==posicion){
            return temp->dato;
        }temp=temp->next;
    }return "No se encontro";
}
//main.cpp
