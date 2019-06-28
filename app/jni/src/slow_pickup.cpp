#include "slow_pickup.h"

const int SlowPickup::SPAWN_DELAY_MS = 2000;
const int SlowPickup::EFFECT_TIME = 1000;

SlowPickup::SlowPickup(Video &video,
                       int initX,
                       int initY) :
        Pickup(video, "pickups/snail.png", 0, 0, PICKUP_WIDTH, PICKUP_HEIGHT, initX, initY, true){

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
