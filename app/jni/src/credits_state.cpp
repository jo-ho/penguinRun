//
// Created by Admin on 2020-04-24.
//

#include "credits_state.h"
#include "asset_manager.h"

CreditsState::CreditsState(std::shared_ptr<StateMachine> stateMachine, Video &video) {
    this->video = video;
    this->stateMachine = stateMachine;

    background = AssetManager::Get()->GetSprite("credits_frame");
    backButton = std::unique_ptr<ImageButton>(new ImageButton(
            video, "back_unpressed", "back_pressed",
            0, video.getScreenSizeH() - AssetManager::SMALL_BUTTON_SIZE,
            [sm = stateMachine]() {sm->change(MAIN_MENU, nullptr);}));
}

State::StateType CreditsState::getStateType() {
    return CREDITS;
}

void CreditsState::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event) != 0) {
        if (event.type == SDL_QUIT) {
            stateMachine->stopRunning();
        }
        backButton->handleEvent(event, AssetManager::SMALL_BUTTON_SIZE, AssetManager::SMALL_BUTTON_SIZE);

    }
}

void CreditsState::update(int elapsedTime) {

}

void CreditsState::render() {
    video.clear();
    background->renderStretchToBackground(video, 0, 0);
    backButton->render(AssetManager::SMALL_BUTTON_SIZE, AssetManager::SMALL_BUTTON_SIZE);

    video.present();
}

void CreditsState::onEnter(void *param) {

}

void CreditsState::onExit() {

}


