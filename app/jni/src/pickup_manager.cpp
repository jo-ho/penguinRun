#include <SDL.h>

#include "pickup_manager.h"
#include "score_pickup.h"
#include "player.h"
#include "speed_pickup.h"
#include "slow_pickup.h"
#include <stdlib.h>
#include <memory>


PickupManager::PickupManager() {}

void PickupManager::spawn(Video & video) {
    if (scorePickupTimer.getTimeElapsedMs()  >= ScorePickup::SPAWN_DELAY_MS) {
        spawnPickup<ScorePickup>(video);
        scorePickupTimer.reset();
    }
    if (speedPickupTimer.getTimeElapsedMs() >= SpeedPickup::SPAWN_DELAY_MS) {
        spawnPickup<SpeedPickup>(video);
        speedPickupTimer.reset();
    }
    if (slowPickupTimer.getTimeElapsedMs() >= SlowPickup::SPAWN_DELAY_MS) {
        spawnPickup<SlowPickup>(video);
        slowPickupTimer.reset();
    }
 }

void PickupManager::update() {
    for (unsigned i = 0; i < pickups.size(); i++) {
        pickups.at(i)->move();
        if (pickups.at(i)->getX() < 0 - Pickup::PICKUP_WIDTH) {
            pickups.at(i).reset();
            pickups.erase(pickups.begin() + i);

        }
    }
}

void PickupManager::render(Video & video) {
    for (unsigned i = 0; i < pickups.size(); i++) {
        pickups.at(i)->renderSprite(video,pickups.at(i)->getX(),pickups.at(i)->getY());
    }
}

void PickupManager::checkCollisions(std::shared_ptr <Player> player){
    for (unsigned i = 0; i < pickups.size(); i++) {
        SDL_Rect collider = pickups.at(i)->getCollider();
        if (player->checkCollision(collider)) {
            pickups.at(i)->activateAction(player);
            pickups.at(i).reset();
            pickups.erase(pickups.begin() + i);
        }
    }

}

template<class Class>
void PickupManager::spawnPickup(Video & video) {
    int randomY = rand() % (video.getScreenSizeH() - SpeedPickup::PICKUP_HEIGHT);
    std::shared_ptr<Class> pickup =
            std::make_shared<Class>(video,
                                          video.getScreenSizeW(),
                                          randomY);
    pickups.push_back(pickup);

}


