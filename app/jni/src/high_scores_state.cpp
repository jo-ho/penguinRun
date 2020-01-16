//
// Created by User on 2020-01-09.
//

#include "high_scores_state.h"
#include "score_manager.h"
#include "colour.h"

HighScoresState::HighScoresState(std::shared_ptr<StateMachine> stateMachine, Video &video) {
    this->stateMachine = stateMachine;
    this->video = video;
    frame = std::unique_ptr<HighScoresFrame>(new HighScoresFrame(video));
    background = std::unique_ptr<Sprite>(new Sprite(
            video, "gui/background2.png",
            0,0,
            BACKGROUND_WIDTH, BACKGROUND_HEIGHT,
            0, 0));


}

State::StateType HighScoresState::getStateType() {
    return HIGH_SCORES;
}

void HighScoresState::handleEvents() {

}

void HighScoresState::update(int elapsedTime) {

}

void HighScoresState::render() {
    video.clear();
    background->renderStretchToBackground(video, 0, 0);
    frame->render();
    video.present();

}

void HighScoresState::onEnter(void *param) {
    frame->updateScores();

}

void HighScoresState::onExit() {

}

