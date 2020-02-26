
#include "score_pickup.h"
#include "colour.h"


const int ScorePickup::SPAWN_DELAY_MS = 500;
const int DEFAULT_SCORE = 20;


ScorePickup::ScorePickup(Video &video,
                         int initX,
                         int initY) :
        Pickup(video, "score_pickup", initX, initY) {

}

void ScorePickup::activateAction(std::unique_ptr<Player> &player) {
    player->increaseScore(DEFAULT_SCORE);
}


