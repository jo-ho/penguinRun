#ifndef SLOWPICKUP_H
#define SLOWPICKUP_H

#include "pickup.h"

class SlowPickup : public Pickup {
    public:
        const static int SPAWN_DELAY_MS;
        SlowPickup(Video & video,
                   int initX,
                   int initY);
};


#endif
