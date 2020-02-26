#include "death_pickup.h"
#include "colour.h"

const int DeathPickup::SPAWN_DELAY_MS = 1000;

DeathPickup::DeathPickup(Video &video,
                         int initX,
                         int initY) :
        Pickup(video, "death_pickup", initX, initY) {
}

void DeathPickup::activateAction(std::unique_ptr<Player> &player) {
    if (player->getDamagedState() == SHIELDED) {
        player->setDamagedState(UNHURT);
    } else {
        player->setDamagedState(DEAD);
    }
}

