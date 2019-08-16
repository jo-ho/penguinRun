#include <SDL.h>
#include "play_state.h"
#include "player.h"
#include "colour.h"



PlayState::PlayState(std::shared_ptr<StateMachine> stateMachine, Video &video) {
    this->stateMachine = stateMachine;
    this->video = video;
    player = std::unique_ptr<Player>(new Player(video));
    pickupManager = std::unique_ptr<PickupManager>(new PickupManager());
    background = std::unique_ptr<ScrollableBackground>(new ScrollableBackground(video, "under.png", 1024, 768));
    deathAnimation = std::unique_ptr<DeathAnimation>(new DeathAnimation(video));
}

State::StateType PlayState::getStateType() {
    return PLAY;
}

void PlayState::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event) != 0) {
        if (event.type == SDL_QUIT) {
            stateMachine->stopRunning();
        }
        if (player->getDamagedState() != DEAD) {
            if (event.type == SDL_FINGERDOWN) {
                fingerIDs.push_back(event.tfinger.fingerId);
                float touchPosY = event.tfinger.y * video.getScreenSizeH();
                if (touchPosY >= 0 && touchPosY <= video.getScreenSizeH() / 2) {
                    player->setMoveState(MoveState::MOVING_UP);
                } else {
                    player->setMoveState(MoveState::MOVING_DOWN);
                }
            } else if (event.type == SDL_FINGERUP) {
                fingerIDs.erase(
                        std::remove(fingerIDs.begin(), fingerIDs.end(), event.tfinger.fingerId),
                        fingerIDs.end());
                if (fingerIDs.empty()) {
                    player->setMoveState(MoveState::STOPPED);
                }
            } else if (event.type == SDL_USEREVENT) {
                SDL_UserEvent userEvent = event.user;
                if (userEvent.code == 0) {
                    pickupManager->spawn(video, userEvent.data1);
                }
            }
        }
    }

}

void PlayState::update(int elapsedTime) {
    if (player->getDamagedState() != DEAD) {
        pickupManager->checkCollisions(player);
        player->update(video.getScreenSizeH(), elapsedTime);
        background->update(video.getScreenSizeW());
        pickupManager->update(video.getScreenSizeH());
    } else {
        if (!deathAnimationComplete) deathAnimation->updateSprite(elapsedTime);

        if (deathAnimation->getNumCompletedLoops() == 1) {
            deathAnimationComplete = true;
            stateMachine->change(MAIN_MENU, NULL);
        }
    }
}

void PlayState::render() {
    video.clear();
    background->render(video);
    text.render(video, std::to_string(player->getScore()).c_str(), Colour::black, 0, 0);
    if (player->getDamagedState() != DEAD) {
        player->render(video);
        pickupManager->render(video);
    } else {
        if (!deathAnimationComplete) deathAnimation->renderSprite(video, player->getX(), player->getY());
    }
    video.present();
}

void PlayState::onEnter(void * param) {
    pickupManager->createTimers(video);
    deathAnimationComplete = false;
}

void PlayState::onExit() {
    player.reset(new Player(video));
    pickupManager.reset(new PickupManager());
    deathAnimation.reset(new DeathAnimation(video));

}
