#include "death_pickup.h"
#include "colour.h"

const int DeathPickup::SPAWN_DELAY_MS = 2000;

DeathPickup::DeathPickup(int initX, int initY) :
        Pickup("death_pickup", initX, initY) {
}

void DeathPickup::activateAction(std::unique_ptr<Player> &player) {
    if (player->getDamagedState() == SHIELDED) {
        player->setDamagedState(UNHURT);
    } else {
        player->setDamagedState(DEAD);
    }
}

