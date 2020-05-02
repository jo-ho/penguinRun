
#include "score_pickup.h"
#include "colour.h"


const int ScorePickup::SPAWN_DELAY_MS = 1000;
const int DEFAULT_SCORE = 20;


ScorePickup::ScorePickup(int initX, int initY) :
        Pickup("score_pickup", initX, initY) {

}

void ScorePickup::activateAction(std::unique_ptr<Player> &player) {
    player->increaseScore(DEFAULT_SCORE);
}


