//
// Created by User on 2020-01-13.
//

#include "high_scores_frame.h"
#include "score_manager.h"
#include "colour.h"


HighScoresFrame::HighScoresFrame(Video &video) {
    this->video = video;
    background = std::unique_ptr<Sprite>(new Sprite(video, "gui/frames/hi-score-new.png",
                                                    0, 0,
                                                    HIGH_SCORES_FRAME_WIDTH,
                                                    HIGH_SCORES_FRAME_HEIGHT,
                                                    0, 0,
                                                    &Colour::black));
    w =  HIGH_SCORES_FRAME_WIDTH / 3;
    h = HIGH_SCORES_FRAME_HEIGHT / 3;
    x = (video.getScreenSizeW() -  w) /2;
    y = (video.getScreenSizeH() -  h) /2;

    updateScores();

}

void HighScoresFrame::render() {
    background->renderSprite(video, x, y, w, h);
    if (scores.size() > 0) {
        firstScore.render(video, std::to_string(scores.at(0)).c_str(), Colour::black,
                x + SCORE_OFFSET_X / 3, y + FIRST_SCORE_OFFSET_Y / 3);
    }
    if (scores.size() > 1) {
        secondScore.render(video, std::to_string(scores.at(1)).c_str(), Colour::black,
                          x + SCORE_OFFSET_X / 3, y + SECOND_SCORE_OFFSET_Y / 3);
    }
    if (scores.size() > 2) {
        thirdScore.render(video, std::to_string(scores.at(2)).c_str(), Colour::black,
                          x + SCORE_OFFSET_X / 3, y + THIRD_SCORE_OFFSET_Y / 3);
    }
}

void HighScoresFrame::updateScores() {
    scores = ScoreManager::Get()->getScores();
    std::sort(scores.begin(), scores.end(),  std::greater<int>());
}


