#include <memory>
#include "main_menu_state.h"
#include "colour.h"
#include "file_manager.h"
#include "score_manager.h"
#include "asset_manager.h"

MainMenuState::MainMenuState(std::shared_ptr<StateMachine> stateMachine, Video & video) {
    this->stateMachine = stateMachine;

    this->video = video;

    background = AssetManager::Get()->GetSprite("main_menu_bg");
    title = std::unique_ptr<StaticText>(new StaticText(video, "akashi96", "Penguin Run", Colour::navy));



    row = std::make_unique<ImageButtonRow>(0, 0, video.getScreenSizeW(), video.getScreenSizeH(),
                                                             BUTTON_SIZE, video.getScreenSizeH() - video.getScreenSizeH() / 4);
    row->add(new ImageButton(
            video, "play_unpressed", "play_pressed",
            0, 0, [sm = stateMachine]() { sm->change(PLAY, nullptr); }));
    row->add(new ImageButton(
            video, "records_unpressed", "records_pressed",
            0, 0, [sm = stateMachine]() {sm->change(HIGH_SCORES, nullptr);}));
    row->add(new ImageButton(
            video, "help_unpressed", "help_pressed",
            0, 0, [sm = stateMachine]() {sm->change(HELP, nullptr);}));
    row->add(new ImageButton(
            video, "home_unpressed", "home_pressed",
            0, 0, [sm = stateMachine]() {sm->stopRunning();}));

    creditsButton = std::unique_ptr<ImageButton>(new ImageButton(video, "credits_unpressed", "credits_pressed",
            video.getScreenSizeW() - AssetManager::SMALL_BUTTON_SIZE, 0, [sm = stateMachine]() {sm->change(CREDITS, nullptr);}));

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
        creditsButton->handleEvent(event, AssetManager::SMALL_BUTTON_SIZE, AssetManager::SMALL_BUTTON_SIZE);

    }

}

void MainMenuState::update(int elapsedTime) {

}

void MainMenuState::render() {
    video.clear();
    background->renderStretchToBackground(video, 0, 0);
    title->render(video, video.getScreenSizeW() / 2 - title->w, video.getScreenSizeH() / 4);
    row->render();
    creditsButton->render(AssetManager::SMALL_BUTTON_SIZE, AssetManager::SMALL_BUTTON_SIZE);
    video.present();

}

void MainMenuState::onEnter(void * param) {

}

void MainMenuState::onExit() {

}


