#include "Adapter.h"

/*    Recibe tres entradas de conexión:  EUSocket  (Tierra, Neutro y Activo) */
void Adapter::plugIn(EuropeanSocketInterface* outlet) {
        adapterSocket = outlet;  // Conexion del Toma Corrientes con el Enchufe Adaptador.
    }

/*    Salen solamente las entradas compatibles:  CRSocket  ( Neutro y Activo) */
Cable Adapter::live() {
    return adapterSocket->live();
}

Cable Adapter::neutral() {
    return adapterSocket->neutral();
}

int Adapter::voltage() {
    return 110;
}