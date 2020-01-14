//
// Created by User on 2020-01-13.
//

#ifndef GAME1_HIGH_SCORES_FRAME_H
#define GAME1_HIGH_SCORES_FRAME_H

static const int HIGH_SCORES_FRAME_WIDTH = 2102;

static const int HIGH_SCORES_FRAME_HEIGHT = 2121;


#include "video.h"
#include "sprite.h"

class HighScoresFrame {
public:
    HighScoresFrame(Video & video);
    void render();

private:
    Video video;
    std::unique_ptr<Sprite> background;


    int x, y, w, h;
};


#endif //GAME1_HIGH_SCORES_FRAME_H
