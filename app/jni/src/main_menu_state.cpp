#include "main_menu_state.h"
#include "button.h"

MainMenuState::MainMenuState(std::shared_ptr<StateMachine> stateMachine, Video & video) {
    this->stateMachine = stateMachine;

    this->video = video;

    playButton = std::unique_ptr<ImageButton>(new ImageButton(
            video, "gui/buttons/normal/play.png", "gui/buttons/click/play.png",
            0, 0, 701, 701,
            0, 0, false));
}

State::StateType MainMenuState::getStateType() {
    return StateType::MAIN_MENU;
}

void MainMenuState::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event) != 0) {
        if (event.type == SDL_QUIT) {
            stateMachine->stopRunning();
        }
        if (playButton->handleEvent(event)) {
            stateMachine->change(PLAY, nullptr);
        }

    }

}

void MainMenuState::update(int elapsedTime) {

}

void MainMenuState::render() {
    video.clear();
    playButton->render();
    video.present();

}

void MainMenuState::onEnter(void * param) {

}

void MainMenuState::onExit() {

}


