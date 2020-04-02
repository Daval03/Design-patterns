#import "patron de diseño/libreria.h++"
#import "patron de diseño/producto.h++"
//import  "Adapter Pattern"
using namespace std;
int main() {
    libreria lib;
    producto libro1("Mate"),libro2("Fisica"),libro3("Electro");
    lib.Attach(&libro1);
    lib.Attach(&libro2);
    lib.Attach(&libro3);
    lib.setState(1000);
}
