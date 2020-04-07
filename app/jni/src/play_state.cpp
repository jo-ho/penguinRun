#include <SDL.h>
#include "play_state.h"
#include "player.h"
#include "colour.h"
#include "image_button.h"
#include "collision.h"
#include "score_manager.h"


PlayState::PlayState(std::shared_ptr<StateMachine> stateMachine, Video &video) {
    this->stateMachine = stateMachine;
    this->video = video;
    player = std::unique_ptr<Player>(new Player(video));
    pickupManager = std::unique_ptr<PickupManager>(new PickupManager());
    background = std::unique_ptr<ScrollableBackground>(new ScrollableBackground("play_bg"));
    deathAnimation = std::unique_ptr<DeathAnimation>(new DeathAnimation(video));
    moveAreaHeight = video.getScreenSizeH() - (video.getScreenSizeH() / FLOOR_HEIGHT_FACTOR);

    pauseButton = std::unique_ptr<ImageButton>(new ImageButton(
            video,
            "paused_unpressed", "paused_pressed",
            video.getScreenSizeW() - PAUSE_BUTTON_SIZE, 0,
            [this]() {this->paused = true;}));
    paused = false;
    pauseMenu = std::unique_ptr<PauseMenu>(new PauseMenu(video));

    pauseMenu->add(new ImageButton(
            video, "play_unpressed", "play_pressed",
            0, 0, [this]() {this->paused = false;}));
    pauseMenu->add(new ImageButton(
            video, "home_unpressed", "home_pressed",
            0, 0, [stateMachine]() {stateMachine->change(MAIN_MENU, NULL);}));
    postGameMenu = std::unique_ptr<PostGameMenu>(new PostGameMenu(video));
    postGameMenu->add(new ImageButton(
            video, "play_unpressed", "play_pressed",
            0, 0, [stateMachine]() {stateMachine->change(PLAY, NULL);}));
    postGameMenu->add(new ImageButton(
            video, "home_unpressed", "home_pressed",
            0, 0, [stateMachine]() {stateMachine->change(MAIN_MENU, NULL);}));
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
        if (!paused) {
            if (player->getDamagedState() != DEAD) {
                pauseButton->handleEvent(event, PAUSE_BUTTON_SIZE, PAUSE_BUTTON_SIZE);
                handleInput(event);
                if (event.type == SDL_USEREVENT) {
                    SDL_UserEvent userEvent = event.user;
                    if (userEvent.code == 0) {
                        pickupManager->spawn(video, userEvent.data1, moveAreaHeight);
                    }
                } else if (event.type == SDL_APP_WILLENTERFOREGROUND) {
                    pickupManager->resumeTimers();
                } else if (event.type == SDL_APP_DIDENTERBACKGROUND) {
                    player->setMoveState(MoveState::STOPPED);

                    pickupManager->stopTimers();
                }
            } else {
                if (deathAnimation->getNumCompletedLoops() == 1) postGameMenu->handleEvent(event);
            }

        } else {
            player->setMoveState(MoveState::STOPPED);
            pauseMenu->handleEvent(event);
        }
    }

}

void PlayState::update(int elapsedTime) {
    if (!paused) {
        if (player->getDamagedState() != DEAD) {
            pickupManager->checkCollisions(player);
            player->update(moveAreaHeight, elapsedTime);
            background->update(video.getScreenSizeW());
            pickupManager->update(moveAreaHeight, elapsedTime);
        } else {
            if (deathAnimation->getNumCompletedLoops() < 1) deathAnimation->updateSprite(elapsedTime);
        }
    }
}

void PlayState::render() {
    video.clear();
    background->render(video);
    score.render(video, std::to_string(player->getScore()).c_str(), Colour::white, 5 , 5);
    pauseButton->render(PAUSE_BUTTON_SIZE, PAUSE_BUTTON_SIZE);
    if (player->getDamagedState() != DEAD) {
        player->render(video);
        pickupManager->render(video);
    } else {
        if (deathAnimation->getNumCompletedLoops() < 1) deathAnimation->renderSprite(video, player->getX(), player->getY());
        else {

            postGameMenu->render(player->getScore());
        }
    }
    if (paused) pauseMenu->render();
    video.present();
}

void PlayState::onEnter(void * param) {
    pickupManager->resumeTimers();
}

void PlayState::onExit() {
    player.reset(new Player(video));
    pickupManager.reset(new PickupManager());
    deathAnimation.reset(new DeathAnimation(video));
    paused = false;

}

void PlayState::pause() {
    paused = true;
}

void PlayState::handleInput(SDL_Event & event) {
    if (event.type == SDL_FINGERDOWN) {
        fingerIDs.push_back(event.tfinger.fingerId);
        float touchPosY = event.tfinger.y * video.getScreenSizeH();
        float touchPosX = event.tfinger.x * video.getScreenSizeW();
        SDL_Rect pauseButtonArea = {pauseButton->getX(), pauseButton->getY(), PAUSE_BUTTON_SIZE, PAUSE_BUTTON_SIZE};
        if (!Collision::PointInRect(touchPosX, touchPosY, pauseButtonArea)) {
            if (touchPosY >= 0 && touchPosY <= video.getScreenSizeH() / 2) {
                player->setMoveState(MoveState::MOVING_UP);
            } else {
                player->setMoveState(MoveState::MOVING_DOWN);
            }
        }
    } else if (event.type == SDL_FINGERUP) {
        fingerIDs.erase(
                std::remove(fingerIDs.begin(), fingerIDs.end(), event.tfinger.fingerId),
                fingerIDs.end());
        if (fingerIDs.empty()) {
            player->setMoveState(MoveState::STOPPED);
        }
    }
}
