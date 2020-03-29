#include "producto.h++"
producto::producto(string nombre) {
    this->nombre=nombre;
}
void producto::update(int price) {
    cout<<nombre+" precio:"+to_string(price);
}