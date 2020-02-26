#include "shield_pickup.h"
#include "colour.h"

const int ShieldPickup::SPAWN_DELAY_MS = 4000;

ShieldPickup::ShieldPickup(Video &video,
                           int initX,
                           int initY) :
        Pickup(video, "shield_pickup", initX, initY){
}

void ShieldPickup::activateAction(std::unique_ptr<Player> &player) {
    player->setDamagedState(SHIELDED);

}
