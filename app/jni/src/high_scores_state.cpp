//
// Created by User on 2020-01-09.
//

#include "high_scores_state.h"
#include "score_manager.h"
#include "colour.h"
#include "asset_manager.h"

HighScoresState::HighScoresState(std::shared_ptr<StateMachine> stateMachine, Video &video) {
    this->stateMachine = stateMachine;
    this->video = video;
    frame = std::unique_ptr<HighScoresFrame>(new HighScoresFrame(video));
    background = AssetManager::Get()->GetSprite("high_scores_bg");
    backButton = std::unique_ptr<ImageButton>(new ImageButton(
            video, "back_unpressed", "back_pressed",
            0, video.getScreenSizeH() - BACK_BUTTON_SIZE,
            [sm = stateMachine]() {sm->change(MAIN_MENU, nullptr);}));


}

State::StateType HighScoresState::getStateType() {
    return HIGH_SCORES;
}

void HighScoresState::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event) != 0) {
        if (event.type == SDL_QUIT) {
            stateMachine->stopRunning();
        }
        backButton->handleEvent(event, BACK_BUTTON_SIZE, BACK_BUTTON_SIZE);

    }
}

void HighScoresState::update(int elapsedTime) {

}

void HighScoresState::render() {
    video.clear();
    background->renderStretchToBackground(video, 0, 0);
    backButton->render(BACK_BUTTON_SIZE, BACK_BUTTON_SIZE);
    frame->render();
    video.present();

}

void HighScoresState::onEnter(void *param) {
    frame->updateScores();

}

void HighScoresState::onExit() {

}

