#ifndef DEATH_PICKUP_H
#define DEATH_PICKUP_H


#include "pickup.h"

class DeathPickup : public Pickup {
public:
    const static int SPAWN_DELAY_MS;
    DeathPickup(Video & video,
                int initX,
                int initY);
    void activateAction(std::unique_ptr<Player> &player);

};

#endif
