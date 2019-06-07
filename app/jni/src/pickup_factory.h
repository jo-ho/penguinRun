#ifndef PICKUP_FACTORY_H
#define PICKUP_FACTORY_H


#include "pickup.h"
#include <memory>


class PickupFactory {
public:
    enum PickupType{SCORE_PICKUP, SLOW_PICKUP, SPEED_PICKUP, DEATH_PICKUP, SHIELD_PICKUP};
    std::shared_ptr<Pickup> getPickup(PickupType pickupType, Video & video, int initX, int initY);
};


#endif
