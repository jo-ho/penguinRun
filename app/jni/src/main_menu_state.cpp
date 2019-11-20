#include <memory>
#include "main_menu_state.h"
#include "button.h"
#include "colour.h"

MainMenuState::MainMenuState(std::shared_ptr<StateMachine> stateMachine, Video & video) {
    this->stateMachine = stateMachine;

    this->video = video;

    row = std::make_unique<ImageButtonRow>(0, 0, video.getScreenSizeW(), video.getScreenSizeH(),
                                                             BUTTON_SIZE, video.getScreenSizeH() - video.getScreenSizeH() / 4);
    row->add(new ImageButton(
            video, "gui/buttons/normal/play.png", "gui/buttons/click/play.png",
            0, 0, BUTTON_SIZE, BUTTON_SIZE,
            0, 0, [sm = stateMachine]() { sm->change(PLAY, nullptr); }, &Colour::black));
    row->add(new ImageButton(
            video, "gui/buttons/normal/records.png", "gui/buttons/click/records.png",
            0, 0, BUTTON_SIZE, BUTTON_SIZE,
            0, 0, []() {}, &Colour::black));
    row->add(new ImageButton(
            video, "gui/buttons/normal/help.png", "gui/buttons/click/help.png",
            0, 0, BUTTON_SIZE, BUTTON_SIZE,
            0, 0, []() {}, &Colour::black));
    row->add(new ImageButton(
            video, "gui/buttons/normal/home.png", "gui/buttons/click/home.png",
            0, 0, BUTTON_SIZE, BUTTON_SIZE,
            0, 0, []() {}, &Colour::black));

    SDL_Log("%d, %d", video.getScreenSizeW(), video.getScreenSizeH());
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
        row->handleEvent(event);

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


