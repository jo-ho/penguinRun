//
// Created by User on 2020-01-13.
//

#include "high_scores_frame.h"

HighScoresFrame::HighScoresFrame(Video &video) {
    this->video = video;
    background = std::unique_ptr<Sprite>(new Sprite(video, "gui/frames/hi-score.png",
                                                    0, 0,
                                                    HIGH_SCORES_FRAME_WIDTH,
                                                    HIGH_SCORES_FRAME_HEIGHT,
                                                    0, 0));
    w =  HIGH_SCORES_FRAME_WIDTH / 3;
    h = HIGH_SCORES_FRAME_HEIGHT / 3;
    x = (video.getScreenSizeW() -  w) /2;
    y = (video.getScreenSizeH() -  h) /2;

}

void HighScoresFrame::render() {
    background->renderSprite(video, x, y, w, h);
}
