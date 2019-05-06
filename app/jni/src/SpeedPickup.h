#ifndef SPEEDPICKUP_H
#define SPEEDPICKUP_H


#include "Pickup.h"

class SpeedPickup : public Pickup {
    public:
        const static int SPAWN_DELAY_MS;
        SpeedPickup(Video & video,
                int initX,
                int initY);

};


#endif