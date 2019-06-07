#include "shield_pickup.h"

const int ShieldPickup::SPAWN_DELAY_MS = 4000;

ShieldPickup::ShieldPickup(Video &video,
                           int initX,
                           int initY) :
        Pickup(video, "pickups/shield_pickup.png", 0, 0, PICKUP_WIDTH, PICKUP_HEIGHT, initX, initY, false){
}

void ShieldPickup::activateAction(std::unique_ptr<Player> &player) {
    player->setDamagedState(SHIELDED);

}
