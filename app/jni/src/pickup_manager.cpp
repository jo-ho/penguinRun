#include <SDL.h>

#include "pickup_manager.h"
#include "score_pickup.h"
#include "player.h"
#include "speed_pickup.h"
#include "slow_pickup.h"
#include "death_pickup.h"
#include <stdlib.h>
#include <memory>

PickupManager::PickupManager() {}

void PickupManager::spawn(Video & video, void * code) {
    intptr_t pSpawnCode = reinterpret_cast<intptr_t>(code);
    Code spawnCode = static_cast<Code>(pSpawnCode);
    switch (spawnCode) {
        case SCORE_PICKUP: spawnPickup<ScorePickup>(video);
            break;
        case SLOW_PICKUP: spawnPickup<SlowPickup>(video);
            break;
        case SPEED_PICKUP: spawnPickup<SpeedPickup>(video);
            break;
        case DEATH_PICKUP: spawnPickup<DeathPickup>(video);
            break;
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
    int randomY = rand() % (video.getScreenSizeH() - Pickup::PICKUP_HEIGHT);
    std::shared_ptr<Class> pickup =
            std::make_shared<Class>(video,
                                          video.getScreenSizeW(),
                                          randomY);
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
    SDL_AddTimer(ScorePickup::SPAWN_DELAY_MS, pushEventToQueue, (void *) SCORE_PICKUP);
    SDL_AddTimer(SlowPickup::SPAWN_DELAY_MS, pushEventToQueue, (void *) SLOW_PICKUP);
    SDL_AddTimer(SpeedPickup::SPAWN_DELAY_MS, pushEventToQueue, (void *) SPEED_PICKUP);
    SDL_AddTimer(DeathPickup::SPAWN_DELAY_MS, pushEventToQueue, (void *) DEATH_PICKUP);
}




