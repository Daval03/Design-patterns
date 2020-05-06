#include "Pruebas de la progra 1/SmartPtr.h++"
#include "Pruebas de la progra 1/HashTable.cpp"

using namespace std;
int main() {

    HashTable<int, int* > hashTable;
    SmartPtr<int> ptr1(new int(1));
    SmartPtr<int> ptr2(new int(2));
    SmartPtr<int> ptr3(new int(3));

    hashTable.set(ptr1.getID(), &(*ptr1));
    hashTable.set(ptr2.getID(), &(*ptr2));
    hashTable.set(ptr3.getID(), &(*ptr3));

    cout << "ptr1 ID\t" <<  ptr1.getID() << endl;
    cout << "ptr2 ID\t" <<  ptr2.getID() << endl;
    cout << "ptr3 ID\t" <<  ptr3.getID() << endl << endl;

    cout << "ptr1 memoryAds\t" <<  hashTable.get(ptr1.getID())<< endl;
    cout << "ptr2 memoryAds\t" <<  hashTable.get(ptr2.getID())<< endl;
    cout << "ptr3 memoryAds\t" <<  hashTable.get(ptr3.getID())<< endl << endl;

    ptr1 = ptr2;
    cout << "PTR1\t" << *ptr1 << endl << &(*ptr1) << endl;
    cout << "PTR2\t" << *ptr2 << endl << &(*ptr2) << endl << endl;

    cout << "PTR1 hashAds\t" <<  hashTable.get(ptr1.getID()) << endl;
    cout << "PTR2 hashAds\t" <<  hashTable.get(ptr2.getID()) << endl;




}