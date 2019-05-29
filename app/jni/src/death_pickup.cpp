#include "death_pickup.h"

const int DeathPickup::SPAWN_DELAY_MS = 2000;

DeathPickup::DeathPickup(Video &video,
                         int initX,
                         int initY) :
        Pickup(video, "pickups/death_pickup.png", 0, 0, PICKUP_WIDTH, PICKUP_HEIGHT, initX, initY, false) {
}

void DeathPickup::activateAction(std::shared_ptr<Player> player) {
}
