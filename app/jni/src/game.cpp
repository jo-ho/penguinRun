#include <SDL.h>


#include "game.h"
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <SDL_ttf.h>


Game::Game() : text(32){

    video.init();
    pickupManager = new PickupManager();
    initSprites();
    menuLoop();
    srand (time(NULL));
}


Game::~Game() {
    SDL_Quit();
    TTF_Quit();
}

void Game::initSprites() {
    for (int i = 0; i < NUM_BUTTONS_MENU; i++) {
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
    player = std::make_shared<Player>(video);
}

// TODO: refactor into different class?
void Game::menuLoop() {
    bool quit = false;
    SDL_Event event;

    while (!quit) {
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            else if (event.type == SDL_FINGERUP) {
                for (unsigned i = 0; i < NUM_BUTTONS_MENU; i++) {
                    if (buttons.at(i)->checkTouch(event.tfinger.x * video.getScreenSizeW(),
                                                  event.tfinger.y * video.getScreenSizeH())) {
                        switch(i) {
                            case buttonID::MENU_BUTTON_START:
                                startGame();
                                break;
                            case buttonID::MENU_BUTTON_OPTIONS:
                                break;
                            case buttonID::MENU_BUTTON_QUIT:
                                quit = true;
                                break;
                        }
                    }
                }
            }
        }
        renderMenu();
    }
}


void Game::renderMenu() {
    video.clear();
    for (unsigned i = 0; i < NUM_BUTTONS_MENU; i++) {
        buttons.at(i)->renderSprite(video,buttons.at(i)->getX(),buttons.at(i)->getY());
    }
    video.present();
}

void Game::startGame() {
    gameLoop();
}


void Game::gameLoop() {
    bool quit = false;
    SDL_Event event;

    // To keep track of last lifted finger
    std::vector<long long> fingerIDs;
    int lastUpdateTime = SDL_GetTicks();

    while (!quit) {
        pickupManager->spawn(video);

        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            else if (event.type == SDL_FINGERDOWN) {
                fingerIDs.push_back(event.tfinger.fingerId);
                float touchPosY = event.tfinger.y * video.getScreenSizeH();
                if (touchPosY >= 0 && touchPosY <= video.getScreenSizeH() / 2) {
                    player->startMoveUp();
                } else {
                    player->startMoveDown();
                }
            }
            else if (event.type == SDL_FINGERUP) {
                fingerIDs.erase(std::remove(fingerIDs.begin(), fingerIDs.end(), event.tfinger.fingerId), fingerIDs.end());
                if (fingerIDs.empty()) {
                    player->stopMove();
                }
            }
        }
        const int currentTime = SDL_GetTicks();
        updateGame(currentTime - lastUpdateTime);
        lastUpdateTime = currentTime;
        checkCollisions();
        renderGame();
    }
}

void Game::renderGame() {
    video.clear();
    player->renderSprite(video, 0, player->getY());
    text.render(video, std::to_string(player->getScore()).c_str(), {0,0,0}, 0, 0);
    pickupManager->render(video);
    video.present();
}

void Game::updateGame(int elapsedTime) {
    player->updatePos(video.getScreenSizeH());
    player->updateSprite(elapsedTime);
    pickupManager->update();
}


void Game::checkCollisions() {
    pickupManager->checkCollisions(player);
}

