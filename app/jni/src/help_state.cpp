//
// Created by User on 2020-01-19.
//

#include "help_state.h"
#include "colour.h"

HelpState::HelpState(std::shared_ptr<StateMachine> stateMachine, Video &video) {
    this->video = video;
    this->stateMachine = stateMachine;

    background = std::unique_ptr<Sprite>(new Sprite(
            video, "gui/frames/level_select.png",
            0,0,
            BACKGROUND_WIDTH, BACKGROUND_HEIGHT,
            0, 0));
    backButton = std::unique_ptr<ImageButton>(new ImageButton(
            video, "gui/buttons/normal/left.png", "gui/buttons/click/left.png",
            0, 0, BACK_BUTTON_SPRITE_SIZE, BACK_BUTTON_SPRITE_SIZE,
            0, video.getScreenSizeH() - BACK_BUTTON_SIZE,
            [sm = stateMachine]() {sm->change(MAIN_MENU, nullptr);}, &Colour::black));
    penguin = std::unique_ptr<Sprite>(new Sprite(
            video, "penguin-gray_new.png",
            0, 52, 30, 52,
            0, 0, &Colour::white));
    scorePickup = std::unique_ptr<Sprite>(new Sprite(
            video, "pickups/fried-fish.png",
            0, 0, 64, 64,
            0, 0));
    deathPickup = std::unique_ptr<Sprite>(new Sprite(
            video, "pickups/skull-crossed-bones.png",
            0, 0, 64, 64,
            0, 0));
    shieldPickup = std::unique_ptr<Sprite>(new Sprite(
            video, "pickups/shield.png",
            0, 0, 64, 64,
            0, 0));
    slowPickup = std::unique_ptr<Sprite>(new Sprite(
            video, "pickups/snail.png",
            0, 0, 64, 64,
            0, 0));
    fastPickup = std::unique_ptr<Sprite>(new Sprite(
            video, "pickups/sprint.png",
            0, 0, 64, 64,
            0, 0));
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
    const int padding = video.getScreenSizeH() / 10;
    int yCursor =  padding;
    const int descX = video.getScreenSizeW() / 3;
    const int spriteX = video.getScreenSizeW() / 4;
    penguin->renderSprite(video, spriteX, yCursor, 30 * 1.5, 52 * 1.5);
    desc.render(video, "This is your character.", Colour::black, descX, yCursor);
    yCursor += 32;
    desc.render(video, "Tap the top half of the screen to move up",
            Colour::black, descX, yCursor);
    yCursor += 32;
    desc.render(video, "and the bottom half to move down.",
            Colour::black, descX, yCursor);
    yCursor += padding;
    title.render(video, "Pickups", Colour::black, video.getScreenSizeW() / 8, yCursor);

    yCursor += padding;
    scorePickup->renderSprite(video, spriteX, yCursor);
    desc.render(video, "Grants you points.", Colour::black, descX, yCursor);

    yCursor += padding;
    deathPickup->renderSprite(video, spriteX, yCursor);
    desc.render(video, "Kills you.", Colour::black, descX, yCursor);

    yCursor += padding;
    shieldPickup->renderSprite(video, spriteX, yCursor);
    desc.render(video, "Protects against one hit", Colour::black, descX, yCursor);

    yCursor += padding;
    slowPickup->renderSprite(video, spriteX, yCursor);
    desc.render(video, "Slows your movement for one second", Colour::black, descX, yCursor);

    yCursor += padding;
    fastPickup->renderSprite(video, spriteX, yCursor);
    desc.render(video, "Speeds up your movement for one second", Colour::black, descX, yCursor);

    backButton->render(BACK_BUTTON_SIZE, BACK_BUTTON_SIZE);
    video.present();


}

void HelpState::onEnter(void *param) {

}

void HelpState::onExit() {

}
