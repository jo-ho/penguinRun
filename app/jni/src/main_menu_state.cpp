#include "main_menu_state.h"
#include "button.h"

MainMenuState::MainMenuState(std::shared_ptr<StateMachine> stateMachine, Video & video) {
    this->stateMachine = stateMachine;

    this->video = video;

        for (int i = 0; i < 3; i++) {
        buttons.push_back(std::unique_ptr<Button>(new Button(video,
                                                   "buttons-384_192.png",
                                                   Button::BUTTON_WIDTH*i,
                                                   0,
                                                   Button::BUTTON_WIDTH,
                                                   Button::BUTTON_HEIGHT,
                                                   0,
                                                   Button::BUTTON_HEIGHT*i,
                                                   false))
        );
    }
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
    else if (event.type == SDL_FINGERUP) {
        for (unsigned i = 0; i < 3; i++) {
            if (buttons.at(i)->checkTouch(event.tfinger.x * video.getScreenSizeW(),
                                          event.tfinger.y * video.getScreenSizeH())) {
                switch(i) {
                    case buttonID::MENU_BUTTON_START:
                        stateMachine->change(PLAY, NULL);
                        break;
                    case buttonID::MENU_BUTTON_OPTIONS:
                        break;
                    case buttonID::MENU_BUTTON_QUIT:
                        stateMachine->stopRunning();
                        break;
                }
            }
        }
    }
        }

}

void MainMenuState::update(int elapsedTime) {

}

void MainMenuState::render() {
    video.clear();
    for (unsigned i = 0; i < 3; i++) {
        buttons.at(i)->renderSprite(video,buttons.at(i)->getX(),buttons.at(i)->getY());
    }
    video.present();

}

void MainMenuState::onEnter(void * param) {

}

void MainMenuState::onExit() {

}


