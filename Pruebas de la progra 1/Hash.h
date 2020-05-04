#ifndef DATOS_2___2_0_HASH_H
#define DATOS_2___2_0_HASH_H

#include "SmartPtr.h++"

class Hash {

public:
    explicit Hash(SmartPtr<int> memoryspace);
    int* getMemory();
    void print();
    bool isZero();
    void increaseReferences();
    void decreaseReferences();

private:
    //attributes
    SmartPtr<int> backup;
    int references;
    //methods




};




#endif //DATOS_2___2_0_HASH_H
