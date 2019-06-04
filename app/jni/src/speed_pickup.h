#ifndef SPEEDPICKUP_H
#define SPEEDPICKUP_H

#include "pickup.h"

class SpeedPickup : public Pickup {
    public:
        const static int SPAWN_DELAY_MS;
        const static int EFFECT_TIME;
        SpeedPickup(Video & video,
                int initX,
                int initY);
        void activateAction(std::unique_ptr<Player> &player);

private:
    static Uint32 resetEffects(Uint32 interval, void * param);

};


#endif