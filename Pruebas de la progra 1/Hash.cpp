#include "Hash.h"

Hash::Hash(SmartPtr<int> memoryspace) {
    this->backup=memoryspace;
    this->references=1;
}

int* Hash::getMemory(){
    return this->backup.operator->();
}

void Hash::print() {
    int* memory = this->getMemory();
    cout<< "Hash\t"<<memory<<"\t"<<this->references<<"\n";
}


bool Hash::isZero() {
    return (this->references==0);
}

void Hash::increaseReferences() {
    this->references++;
}

void Hash::decreaseReferences() {
    this->references--;
}























