#include "Pruebas de la progra 1/SmartPtr.h++"
#include "Pruebas de la progra 1/Hash.h"
#include "Pruebas de la progra 1/LinkedList.cpp"
#include "string"
using namespace std;
int main() {

    SmartPtr<int> ptr1(new int());
    SmartPtr<int> ptr2(new int());

    /*
    *ptr1 = 1;
    //llamada al gbcollector
    Hash hash1(*&ptr1);

    *ptr2 = 2;
    //llamada al gbcollector
    Hash hash2(*&ptr2);

    //Print punteros
    cout<< "Ptr1   \t"<< *ptr1 << "\t" << &*ptr1<< "\n";
    cout<< "Ptr2   \t"<< *ptr2 << "\t" << &*ptr2<< "\n";
    //Cambio
    ptr1=ptr2; cout<< "\n-- -- -- -- -- -- --\n";
//    hash2.

    cout<< "Ptr1   \t"<< *ptr1 << "\t" << &*ptr1<< "\n";
    cout<< "Ptr2   \t"<< *ptr2 << "\t" << &*ptr2<< "\n";
    //Hashes
    cout<< "\nMemoryLeaked"<<"\n";
//    hash1.print();
//    hash2.print();

*/


}
