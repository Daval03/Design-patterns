#ifndef DATOS_2___2_0_ADAPTER_H
#define DATOS_2___2_0_ADAPTER_H

#include "CRSocketInterface.h"
#include "EuropeanSocketInterface.h"

typedef int Cable; // wire with electrons :-)

/* The Adapter */
class Adapter : public CRSocketInterface {
    EuropeanSocketInterface* adapterSocket;

public:
    void plugIn(EuropeanSocketInterface* outlet);
    int voltage();
    Cable live();
    Cable neutral();
};


#endif //DATOS_2___2_0_ADAPTER_H
