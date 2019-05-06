#include <SDL.h>

#include "PickupManager.h"
#include "ScorePickup.h"
#include "Player.h"
#include "SpeedPickup.h"
#include <stdlib.h>
#include <memory>


PickupManager::PickupManager(Video &video) {
    this->video = video;
    scorePickupTimer.reset();
    speedPickupTimer.reset();
}

void PickupManager::spawn() {
    if (scorePickupTimer.getTimeElapsedMs()  >= ScorePickup::SPAWN_DELAY_MS) {
        spawnScorePickup();
        scorePickupTimer.reset();
    }
    if (speedPickupTimer.getTimeElapsedMs() >= SpeedPickup::SPAWN_DELAY_MS) {
        spawnSpeedPickup();
        speedPickupTimer.reset();
    }
}

void PickupManager::spawnScorePickup() {
    int randomY = rand() % (video.getScreenSizeH() - ScorePickup::PICKUP_HEIGHT);
    std::shared_ptr<ScorePickup> scorePickup =
            std::make_shared<ScorePickup>(video,
                                          video.getScreenSizeW(),
                                          randomY);
    pickups.push_back(scorePickup);
}


void PickupManager::spawnSpeedPickup() {
    int randomY = rand() % (video.getScreenSizeH() - SpeedPickup::PICKUP_HEIGHT);
    std::shared_ptr<SpeedPickup> speedPickup =
            std::make_shared<SpeedPickup>(video,
                                          video.getScreenSizeW(),
                                          randomY);
    pickups.push_back(speedPickup);
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
            pickups.at(i).reset();
            pickups.erase(pickups.begin() + i);
        }
    }

}


