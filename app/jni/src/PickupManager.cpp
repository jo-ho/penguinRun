#include <SDL.h>

#include "PickupManager.h"
#include "ScorePickup.h"
#include "Player.h"
#include <stdlib.h>
#include <memory>


PickupManager::PickupManager(Video &video) {
    this->video = video;
    scorePickupSpawnTimer.reset();
}

void PickupManager::spawn() {
    if (scorePickupSpawnTimer.getTimeElapsedMs() >= ScorePickup::SPAWN_DELAY_MS) {
        spawnScorePickup();
        scorePickupSpawnTimer.reset();
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


