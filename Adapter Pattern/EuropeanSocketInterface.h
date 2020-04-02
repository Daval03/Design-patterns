#ifndef DATOS_2___2_0_EUROPEANSOCKETINTERFACE_H
#define DATOS_2___2_0_EUROPEANSOCKETINTERFACE_H

typedef int Cable; // wire with electrons

/* --- Adaptee Interface --- */
class EuropeanSocketInterface {

    public:
        virtual int voltage() = 0;

        virtual Cable live() = 0;
        virtual Cable neutral() = 0;
        virtual Cable earth() = 0;

};


#endif //DATOS_2___2_0_EUROPEANSOCKETINTERFACE_H
