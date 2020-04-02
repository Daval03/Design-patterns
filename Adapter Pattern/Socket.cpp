//
// Created by shakime on 1/4/20.
//

#include "Socket.h"

int Socket::voltage() {
    return 240; //Max Voltage in a house.
}

Cable Socket::live() {
    return 1;
}

Cable Socket::neutral() {
    return -1;
}

Cable Socket::earth() {
    return 0;
}