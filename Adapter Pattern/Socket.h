//
// Created by shakime on 1/4/20.
//

#ifndef DATOS_2___2_0_SOCKET_H
#define DATOS_2___2_0_SOCKET_H

#include "EuropeanSocketInterface.h"

/* Adaptee */
class Socket : public EuropeanSocketInterface {

    public:
        int voltage();

        Cable live();
        Cable neutral();
        Cable earth();

};


#endif //DATOS_2___2_0_SOCKET_H
