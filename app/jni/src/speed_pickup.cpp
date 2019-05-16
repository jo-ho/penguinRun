#include "speed_pickup.h"

const int SpeedPickup::SPAWN_DELAY_MS = 2000;

SpeedPickup::SpeedPickup(Video &video,
                         int initX,
                         int initY) :
        Pickup(video, "pickups/speed_pickup.png", 0, 0, PICKUP_WIDTH, PICKUP_HEIGHT, initX, initY, false){

}

void SpeedPickup::activateAction(std::shared_ptr<Player> player) {

}
