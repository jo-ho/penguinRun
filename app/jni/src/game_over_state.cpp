#include "game_over_state.h"
#include "player.h"

GameOverState::GameOverState(std::shared_ptr<StateMachine> stateMachine, Video &video) {
    this->stateMachine = stateMachine;
    this->video = video;
    deathAnimation = std::unique_ptr<DeathAnimation>(new DeathAnimation(video));
}

State::StateType GameOverState::getStateType() {
    return GAME_OVER;
}

void GameOverState::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event) != 0) {
        if (event.type == SDL_QUIT) {
            stateMachine->stopRunning();
        }
    }

}

void GameOverState::update(int elapsedTime) {
    if (!deathAnimationComplete) deathAnimation->updateSprite(elapsedTime);

    if (deathAnimation->getNumCompletedLoops() == 1) {
        //TODO Retry button
        deathAnimationComplete = true;
        stateMachine->change(MAIN_MENU, NULL);
    }
}

void GameOverState::render() {
    video.clear();
    if (!deathAnimationComplete) deathAnimation->renderSprite(video, player->getX(), player->getY());
    video.present();
}

void GameOverState::onEnter(void *param) {
    player = std::unique_ptr<Player>(static_cast<Player *>(param));
    deathAnimationComplete = false;
}

void GameOverState::onExit() {
    player.reset();
    deathAnimation.reset(new DeathAnimation(video));
}
