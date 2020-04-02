#ifndef DATOS_2___2_0_BLENDER_H
#define DATOS_2___2_0_BLENDER_H


#include "CRSocketInterface.h"
#include <iostream>
using namespace std;

/*--- Client ---*/
class Blender {
    CRSocketInterface* power;

public:
    void plugIn(CRSocketInterface* supply);
    void liquefy();
};



#endif //DATOS_2___2_0_BLENDER_H
