
#include "scorepickup.h"


const int ScorePickup::SPAWN_DELAY_MS = 1000;
const int DEFAULT_SCORE = 20;


ScorePickup::ScorePickup(Video &video,
                         int initX,
                         int initY) :
        Pickup(video, "pickups/score_pickup.png", 0, 0, PICKUP_WIDTH, PICKUP_HEIGHT, initX, initY, false) {

}

void ScorePickup::activateAction(std::shared_ptr<Player> player) {
    player->increaseScore(DEFAULT_SCORE);
}


