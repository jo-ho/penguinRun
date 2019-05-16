#include "slow_pickup.h"

const int SlowPickup::SPAWN_DELAY_MS = 2000;

SlowPickup::SlowPickup(Video &video,
                       int initX,
                       int initY) :
        Pickup(video, "pickups/slow_pickup.png", 0, 0, PICKUP_WIDTH, PICKUP_HEIGHT, initX, initY, false){

}

void SlowPickup::activateAction(std::shared_ptr<Player> player) {
}
