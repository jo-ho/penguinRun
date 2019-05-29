#include <SDL.h>

#include "pickup_manager.h"
#include "score_pickup.h"
#include "player.h"
#include "speed_pickup.h"
#include "slow_pickup.h"
#include "death_pickup.h"
#include "pickup_factory.h"
#include <stdlib.h>
#include <memory>

PickupManager::PickupManager() {}

void PickupManager::spawn(Video & video, void * code) {
    intptr_t pPickupType = reinterpret_cast<intptr_t>(code);
    PickupFactory::PickupType pickupType = static_cast<PickupFactory::PickupType>(pPickupType);
    spawnPickup(video, pickupType);
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

void PickupManager::spawnPickup(Video & video, PickupFactory::PickupType pickupType) {
    int randomY = rand() % (video.getScreenSizeH() - Pickup::PICKUP_HEIGHT);
    PickupFactory pickupFactory;
    std::shared_ptr<Pickup> pickup = pickupFactory
            .getPickup(pickupType, video, video.getScreenSizeW(), randomY);
    pickups.push_back(pickup);
}

Uint32 PickupManager::pushEventToQueue(Uint32 interval, void *param){
    SDL_Event event;
    SDL_UserEvent userEvent;

    userEvent = {.type = SDL_USEREVENT, .code = 0, .data1 = param};
    event = {.type = SDL_USEREVENT, .user = userEvent};

    SDL_PushEvent(&event);
    return interval;
}

void PickupManager::createTimers(Video & video) {
    SDL_AddTimer(ScorePickup::SPAWN_DELAY_MS, pushEventToQueue, (void *) PickupFactory::SCORE_PICKUP);
    SDL_AddTimer(SlowPickup::SPAWN_DELAY_MS, pushEventToQueue, (void *) PickupFactory::SLOW_PICKUP);
    SDL_AddTimer(SpeedPickup::SPAWN_DELAY_MS, pushEventToQueue, (void *) PickupFactory::SPEED_PICKUP);
    SDL_AddTimer(DeathPickup::SPAWN_DELAY_MS, pushEventToQueue, (void *) PickupFactory::DEATH_PICKUP);
}




