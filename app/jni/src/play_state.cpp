#include <SDL.h>
#include "play_state.h"
#include "player.h"

PlayState::PlayState(std::shared_ptr<StateMachine> stateMachine, Video &video) {
    this->stateMachine = stateMachine;
    this->video = video;
    player = std::unique_ptr<Player>(new Player(video));
    pickupManager = std::unique_ptr<PickupManager>(new PickupManager());
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
            else if (event.type == SDL_FINGERDOWN) {
                fingerIDs.push_back(event.tfinger.fingerId);
                float touchPosY = event.tfinger.y * video.getScreenSizeH();
                if (touchPosY >= 0 && touchPosY <= video.getScreenSizeH() / 2) {
                    player->setMoveState(MoveState::MOVING_UP);
                } else {
                    player->setMoveState(MoveState::MOVING_DOWN);
                }
            }
            else if (event.type == SDL_FINGERUP) {
                fingerIDs.erase(std::remove(fingerIDs.begin(), fingerIDs.end(), event.tfinger.fingerId), fingerIDs.end());
                if (fingerIDs.empty()) {
                    player->setMoveState(MoveState::STOPPED);
                }
            }
            else if (event.type == SDL_USEREVENT) {
                SDL_UserEvent userEvent = event.user;
                if (userEvent.code == 0) {
                    pickupManager->spawn(video, userEvent.data1);
                }
            }
        }

    if (player->isDead()) {
        stateMachine->change(MAIN_MENU);
    }

    pickupManager->checkCollisions(player);
}

void PlayState::update(int elapsedTime) {
    player->updatePos(video.getScreenSizeH());
    player->update(elapsedTime);
    pickupManager->update();
}

void PlayState::render() {
    video.clear();
    player->render(video, 0, player->getY());
    text.render(video, std::to_string(player->getScore()).c_str(), {0,0,0}, 0, 0);
    pickupManager->render(video);
    video.present();
}

void PlayState::onEnter() {
    pickupManager->createTimers(video);
}

void PlayState::onExit() {
    player.reset(new Player(video));
    pickupManager.reset(new PickupManager());

}
