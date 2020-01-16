//
// Created by User on 2020-01-13.
//

#ifndef GAME1_HIGH_SCORES_FRAME_H
#define GAME1_HIGH_SCORES_FRAME_H

static const int HIGH_SCORES_FRAME_WIDTH = 2102;

static const int HIGH_SCORES_FRAME_HEIGHT = 2121;

static const int SCORE_OFFSET_X = 868;
static const int FIRST_SCORE_OFFSET_Y = 563;
static const int SECOND_SCORE_OFFSET_Y = 1024;
static const int THIRD_SCORE_OFFSET_Y = 1485;


#include <vector>
#include "video.h"
#include "sprite.h"
#include "text.h"

class HighScoresFrame {
public:
    HighScoresFrame(Video & video);
    void render();
    void updateScores();

private:

    Video video;
    std::unique_ptr<Sprite> background;
    std::vector<int> scores;
    Text firstScore = Text(32);
    Text secondScore = Text(32);
    Text thirdScore = Text(32);


    int x, y, w, h;
};


#endif //GAME1_HIGH_SCORES_FRAME_H
