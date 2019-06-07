#ifndef SHIELD_PICKUP_H
#define SHIELD_PICKUP_H


#include "pickup.h"

class ShieldPickup : public Pickup {
public:
    const static int SPAWN_DELAY_MS;
    ShieldPickup(Video & video,
                int initX,
                int initY);
    void activateAction(std::unique_ptr<Player> &player);

};


#endif
