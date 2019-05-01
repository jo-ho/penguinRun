
#include "scorepickup.h"
#include "../SDL2/include/SDL_rect.h"

const int ScorePickup::SPAWN_DELAY_MS = 1000;


ScorePickup::ScorePickup(Video &video,
                         int initX,
                         int initY) :
        Pickup(video, "pickups/score_pickup.png", 0, 0, PICKUP_WIDTH, PICKUP_HEIGHT, initX, initY, false) {

}


