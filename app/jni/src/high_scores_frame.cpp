//
// Created by User on 2020-01-13.
//

#include "high_scores_frame.h"
#include "score_manager.h"
#include "colour.h"
#include "asset_manager.h"


HighScoresFrame::HighScoresFrame(Video &video) {
    this->video = video;
    background = AssetManager::Get()->GetSprite("high_scores_frame");
    headline = AssetManager::Get()->GetSprite("high_scores_hl");
    w =  HIGH_SCORES_FRAME_WIDTH / 3;
    h = HIGH_SCORES_FRAME_HEIGHT / 3;
    x = (video.getScreenSizeW() -  w) /2;
    y = (video.getScreenSizeH() -  h) /2;

    updateScores();

}

void HighScoresFrame::render() {
    background->renderSprite(video, x, y, w, h);
    headline->renderSprite(video,
            x + w / 2 - HEADLINE_SIZE_W / 2 , y,
            HEADLINE_SIZE_W, HEADLINE_SIZE_H);
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


