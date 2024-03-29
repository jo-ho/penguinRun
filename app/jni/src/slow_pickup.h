#ifndef SLOWPICKUP_H
#define SLOWPICKUP_H

#include "pickup.h"

class SlowPickup : public Pickup {
    public:
        const static int SPAWN_DELAY_MS;
        const static int EFFECT_TIME;
        SlowPickup(int initX, int initY);
        void activateAction(std::unique_ptr<Player> &player);

    private:
        static Uint32 resetEffects(Uint32 interval, void * param);
};


#endif
