#include "Pruebas de la progra 1/SmartPtr.h++"
#include "Pruebas de la progra 1/HashTable.cpp"
#include "Pruebas de la progra 1/LinkedList.cpp"
#include<algorithm>

using namespace std;
int main() {

    HashTable<int, int* > hashTable;
    SmartPtr<int> ptr1(new int(100));
    SmartPtr<int> ptr2(new int(3000));
    hashTable.set(10, &(*ptr1));
    hashTable.set(3, &(*ptr2));
    hashTable.set(7, &(*ptr1));
    hashTable.set(1, &(*ptr1));

//    hashTable.exist(4);
//    hashTable.exist(2);

    hashTable.remove(7);
//    hashTable.exist(1);
    hashTable.print();

//    LinkedList<int> L;
//    L.add(1);
//    L.add(2);
//    L.add(3);
//    L.print();
//    L.removeByName(1);
//    L.removeByName(2);
//    L.removeByName(3);
//
//    L.print();
//
//    hashTable.print();
//    hashTable.remove(1);
//    hashTable.remove(5);

//    cout << "ptr1 ID\t" <<  ptr1.getID() << endl;
//    cout << "ptr2 ID\t" <<  ptr2.getID() << endl << endl;
//
//    cout << "ptr1 memoryAds ->\t" <<  hashTable.get(1)<< endl;
//    cout << "ptr2 memoryAds ->\t" <<  hashTable.get(2)<< endl << endl;
//
//    ptr1 = ptr2;
//    cout << "Cambio" << endl;
//    cout << "PTR1\t" << *ptr1 << "\t" << &(*ptr1) << endl;
//    cout << "PTR2\t" << *ptr2 << "\t" << &(*ptr2) << endl << endl;
//
//    cout << "PTR1 hashBackup ->\t" <<  hashTable.get(1) << endl;
//    cout << "PTR2 hashBackup ->\t" <<  hashTable.get(2) << endl;




}