//
// Created by User on 2020-01-09.
//

#include "high_scores_state.h"
#include "score_manager.h"
#include "colour.h"

HighScoresState::HighScoresState(std::shared_ptr<StateMachine> stateMachine, Video &video) {
    this->stateMachine = stateMachine;
    this->video = video;

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
    if (scores.size() == 1) {
        firstScore.render(video, std::to_string(scores.at(0)).c_str(), Colour::black, 0 , 0);
    }
    video.present();

}

void HighScoresState::onEnter(void *param) {
    scores = ScoreManager::Get()->getScores();
    std::sort(scores.begin(), scores.end(),  std::greater<int>());

}

void HighScoresState::onExit() {

}

