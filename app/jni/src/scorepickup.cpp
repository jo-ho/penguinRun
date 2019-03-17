
#include "scorepickup.h"
#include "../SDL2/include/SDL_rect.h"

const int ScorePickup::SPAWN_DELAY_MS = 1000;
const int ScorePickup::PICKUP_WIDTH = 66;
const int ScorePickup::PICKUP_HEIGHT = 66;

ScorePickup::ScorePickup(Video &video,
                         int initX,
                         int initY) :
        Pickup(video, "pickups/score_pickup.png", 0, 0, PICKUP_WIDTH, PICKUP_HEIGHT, initX, initY, false) {

}

SDL_Rect ScorePickup::getCollider() {
    SDL_Rect collider;
    collider.x = x;
    collider.y = y;
    collider.w = PICKUP_WIDTH;
    collider.h = PICKUP_HEIGHT;
    return collider;
}

