#include "speed_pickup.h"
#include "colour.h"

const int SpeedPickup::SPAWN_DELAY_MS = 3000;
const int SpeedPickup::EFFECT_TIME = 1000;

SpeedPickup::SpeedPickup(int initX, int initY) :
        Pickup("speed_pickup", initX, initY) {

}

void SpeedPickup::activateAction(std::unique_ptr<Player> &player) {
    if (player->getSpeedState() == NORMAL) {
        player->setSpeedState(SpeedState::SPED_UP);
        SDL_AddTimer(EFFECT_TIME, resetEffects, player.get());
    }
}

Uint32 SpeedPickup::resetEffects(Uint32 interval, void *param) {
    Player * player = static_cast<Player*> (param);
    player->setSpeedState(SpeedState::NORMAL);
    return 0;
}
