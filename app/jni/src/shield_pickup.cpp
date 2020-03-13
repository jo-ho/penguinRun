#include "shield_pickup.h"
#include "colour.h"

const int ShieldPickup::SPAWN_DELAY_MS = 4000;

ShieldPickup::ShieldPickup(int initX, int initY) :
        Pickup("shield_pickup", initX, initY) {
}

void ShieldPickup::activateAction(std::unique_ptr<Player> &player) {
    player->setDamagedState(SHIELDED);

}
