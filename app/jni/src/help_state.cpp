//
// Created by User on 2020-01-19.
//

#include "help_state.h"
#include "colour.h"
#include "asset_manager.h"

HelpState::HelpState(std::shared_ptr<StateMachine> stateMachine, Video &video) {
    this->video = video;
    this->stateMachine = stateMachine;

    background = AssetManager::Get()->GetSprite("help_frame");
    backButton = std::unique_ptr<ImageButton>(new ImageButton(
            video, "back_unpressed", "back_pressed",
            0, video.getScreenSizeH() - BACK_BUTTON_SIZE,
            [sm = stateMachine]() {sm->change(MAIN_MENU, nullptr);}));
}

State::StateType HelpState::getStateType() {
    return HELP;
}

void HelpState::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event) != 0) {
        if (event.type == SDL_QUIT) {
            stateMachine->stopRunning();
        }
        backButton->handleEvent(event, BACK_BUTTON_SIZE, BACK_BUTTON_SIZE);

    }

}

void HelpState::update(int elapsedTime) {

}

void HelpState::render() {
    video.clear();
    background->renderStretchToBackground(video, 0, 0);
    backButton->render(BACK_BUTTON_SIZE, BACK_BUTTON_SIZE);
    video.present();


}

void HelpState::onEnter(void *param) {

}

void HelpState::onExit() {

}
