#include "slow_pickup.h"
#include "colour.h"

const int SlowPickup::SPAWN_DELAY_MS = 3000;
const int SlowPickup::EFFECT_TIME = 1000;

SlowPickup::SlowPickup(int initX, int initY) :
        Pickup("slow_pickup", initX, initY) {

}

void SlowPickup::activateAction(std::unique_ptr<Player> &player) {
    if (player->getSpeedState() == NORMAL) {
        player->setSpeedState(SpeedState::SLOWED);
        SDL_AddTimer(EFFECT_TIME, resetEffects, player.get());
    }
}

Uint32 SlowPickup::resetEffects(Uint32 interval, void *param) {
    Player * player = static_cast<Player*> (param);
    player->setSpeedState(SpeedState::NORMAL);
    return 0;
}
