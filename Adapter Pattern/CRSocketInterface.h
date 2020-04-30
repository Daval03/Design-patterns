#ifndef DATOS_2___2_0_CRSOCKETINTERFACE_H
#define DATOS_2___2_0_CRSOCKETINTERFACE_H

typedef int Cable; // wire with electrons

/* --- Target interface --- */
class CRSocketInterface {

    public:
        virtual int voltage() = 0;

        virtual Cable live() = 0;
        virtual Cable neutral() = 0;

};


#endif //DATOS_2___2_0_CRSOCKETINTERFACE_H
