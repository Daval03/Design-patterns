#include "Pruebas de la progra 1/SmartPtr.h++"
#include "string"
using namespace std;
int main() {
    SmartPtr<int> ptr(new int());
    SmartPtr<string> ptr2(new string("Hola"));
    SmartPtr<int> ptr3(new int());
    *ptr=512;
    *ptr3=60;

    cout<<*ptr;
    cout<<"\t";
    cout<<&(*ptr);//Solo imprime la info
    cout<<"\n";
    cout<<*ptr3;
    cout<<"\t";
    cout<<&(*ptr3);
    cout<< "\nDespues del cambio \n";

    ptr=ptr3;

    cout<<*ptr;
    cout<<"\t";
    cout<<&(*ptr);
    cout<<"\n";
    cout<<*ptr3;
    cout<<"\t";
    cout<<&(*ptr3);
}
