
#include "Blender.h"

void Blender::plugIn(CRSocketInterface* supply){
        power = supply;
}

void Blender::liquefy(){
    if (power->voltage() > 120) {
        cout << "Blender is on fire!";
    }
    else if (power->live() == 1 && power->neutral() == -1)
    {
        cout << "Smutty time!";
    }
    else{
        cout << "Something gone wrong!";
    }
}