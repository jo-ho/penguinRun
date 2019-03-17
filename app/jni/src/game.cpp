#include <SDL.h>


#include "game.h"
#include <algorithm>
#include <stdlib.h>
#include <time.h>


Game::Game() {

    // Initialize SDL2
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        SDL_Log("SDL_Init error: %s", SDL_GetError());
    }
    video.init();
    initSprites();
    menuLoop();
    srand (time(NULL));

}


Game::~Game() {
    SDL_Quit();
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
    player = std::make_shared<Player>(video,
                                      "penguin-gray.png",
                                      0,
                                      Player::PLAYER_WIDTH,
                                      Player::PLAYER_HEIGHT,
                                      Player::PLAYER_WIDTH,
                                      0,
                                      video.getScreenSizeH() / 2 - Player::PLAYER_HEIGHT / 2,
                                      false,
                                      Player::NUM_FRAMES,
                                      Player::TARGET_FPS);


}

void Game::menuLoop() {

    bool quit = false;
    SDL_Event event;


    while (!quit) {
        const int startTime = SDL_GetTicks();
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
        const int msPerFrame = 1000 / GAME_FPS;
        const int elapsedTime = SDL_GetTicks() - startTime;
        if (elapsedTime < msPerFrame) {
            SDL_Delay(msPerFrame - elapsedTime);
        }
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

    scorePickupSpawnTimer.reset();

    while (!quit) {
        const int startTime = SDL_GetTicks();

        if (scorePickupSpawnTimer.getTimeElapsedMs() >= ScorePickup::SPAWN_DELAY_MS) {
            spawnScorePickup();
            scorePickupSpawnTimer.reset();
        }

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

        const int msPerFrame = 1000 / GAME_FPS;
        const int elapsedTime = SDL_GetTicks() - startTime;
        if (elapsedTime < msPerFrame) {
            SDL_Delay(msPerFrame - elapsedTime);
        }

    }
}

void Game::renderGame() {
    video.clear();
    player->renderSprite(video, 0, player->getY());
    renderScorePickups();
    video.present();
}

void Game::updateGame(int elapsedTime) {
    player->updatePos(video.getScreenSizeH());
    player->updateSprite(elapsedTime);
    updateScorePickups();
}

void Game::spawnScorePickup() {
    int randomY = rand() % (video.getScreenSizeH() - ScorePickup::PICKUP_HEIGHT);
    std::shared_ptr<ScorePickup> scorePickup =
            std::make_shared<ScorePickup>(video,
                                          video.getScreenSizeW(),
                                          randomY);
    scorePickups.push_back(scorePickup);
}

void Game::renderScorePickups() {
    for (unsigned i = 0; i < scorePickups.size(); i++) {
        scorePickups.at(i)->renderSprite(video,scorePickups.at(i)->getX(),scorePickups.at(i)->getY());
    }
}

void Game::updateScorePickups() {
    for (unsigned i = 0; i < scorePickups.size(); i++) {
        scorePickups.at(i)->move();
        if (scorePickups.at(i)->getX() < 0 - ScorePickup::PICKUP_WIDTH) {
            scorePickups.at(i).reset();
            scorePickups.erase(scorePickups.begin() + i);

        }
    }
}

void Game::checkCollisions() {
    for (unsigned i = 0; i < scorePickups.size(); i++) {
        SDL_Rect collider = scorePickups.at(i)->getCollider();
        if (player->checkCollision(collider)) {
            scorePickups.at(i).reset();
            scorePickups.erase(scorePickups.begin() + i);
        }

    }
}

