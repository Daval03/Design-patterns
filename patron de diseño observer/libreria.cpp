//
// Created by aldo on 28/3/20.
//
#include "libreria.h++"
void libreria::Attach(Observer *obs) {
    observers.push_back(obs);
}
void libreria::Detach(Observer *obs) {
    for(int i=0;i<observers.size();i++){
        if(obs==observers[i])
            observers.erase(observers.begin()+i);
    }
}
void libreria::notify() {
    for(Observer *observer : observers){
        observer->update(price);
    }
}
void libreria::setState(int price) {
    this->price=price;
    notify();
}