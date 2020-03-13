#include "pickup_factory.h"
#include "score_pickup.h"
#include "slow_pickup.h"
#include "speed_pickup.h"
#include "death_pickup.h"
#include "shield_pickup.h"

std::shared_ptr<Pickup>
PickupFactory::getPickup(PickupFactory::PickupType pickupType, Video &video, int initX, int initY) {
    switch (pickupType) {
        case SCORE_PICKUP:
            return std::make_shared<ScorePickup>(initX, initY);
        case SLOW_PICKUP:
            return std::make_shared<SlowPickup>(initX, initY);
        case SPEED_PICKUP:
            return std::make_shared<SpeedPickup>(initX, initY);
        case DEATH_PICKUP:
            return std::make_shared<DeathPickup>(initX, initY);
        case SHIELD_PICKUP:
            return std::make_shared<ShieldPickup>(initX, initY);
    }
}
