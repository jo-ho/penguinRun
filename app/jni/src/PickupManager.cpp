#include <SDL.h>

#include "PickupManager.h"
#include "ScorePickup.h"
#include "Player.h"
#include "SpeedPickup.h"
#include "SlowPickup.h"
#include <stdlib.h>
#include <memory>


PickupManager::PickupManager(Video &video) {
    this->video = video;
    scorePickupTimer.reset();
    speedPickupTimer.reset();
    slowPickupTimer.reset();
}

void PickupManager::spawn() {
    if (scorePickupTimer.getTimeElapsedMs()  >= ScorePickup::SPAWN_DELAY_MS) {
        spawnPickup<ScorePickup>();
        scorePickupTimer.reset();
    }
    if (speedPickupTimer.getTimeElapsedMs() >= SpeedPickup::SPAWN_DELAY_MS) {
        spawnPickup<SpeedPickup>();
        speedPickupTimer.reset();
    }
    if (slowPickupTimer.getTimeElapsedMs() >= SlowPickup::SPAWN_DELAY_MS) {
        spawnPickup<SlowPickup>();
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

void PickupManager::render() {
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
void PickupManager::spawnPickup() {
    int randomY = rand() % (video.getScreenSizeH() - SpeedPickup::PICKUP_HEIGHT);
    std::shared_ptr<Class> pickup =
            std::make_shared<Class>(video,
                                          video.getScreenSizeW(),
                                          randomY);
    pickups.push_back(pickup);

}


