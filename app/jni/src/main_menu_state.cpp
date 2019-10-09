#include <memory>
#include "main_menu_state.h"
#include "button.h"

MainMenuState::MainMenuState(std::shared_ptr<StateMachine> stateMachine, Video & video) {
    this->stateMachine = stateMachine;

    this->video = video;

    row = std::unique_ptr<ImageButtonRow>(new ImageButtonRow(0, 0, video.getScreenSizeW(), video.getScreenSizeH(),
                                                             BUTTON_SIZE));
    row->add(new ImageButton(
            video, "gui/buttons/normal/play.png", "gui/buttons/click/play.png",
            0, 0, BUTTON_SIZE, BUTTON_SIZE,
            0, 0, false));
    row->add(new ImageButton(
            video, "gui/buttons/normal/play.png", "gui/buttons/click/play.png",
            0, 0, BUTTON_SIZE, BUTTON_SIZE,
            0, 0, false));
    row->add(new ImageButton(
            video, "gui/buttons/normal/play.png", "gui/buttons/click/play.png",
            0, 0, BUTTON_SIZE, BUTTON_SIZE,
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

    }

}

void MainMenuState::update(int elapsedTime) {

}

void MainMenuState::render() {
    video.clear();
    row->render();
    video.present();

}

void MainMenuState::onEnter(void * param) {

}

void MainMenuState::onExit() {

}


