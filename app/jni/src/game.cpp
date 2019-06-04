#include <SDL.h>
#include <SDL_ttf.h>
#include "game.h"
#include "main_menu_state.h"
#include "play_state.h"
#include "state.h"

Game::Game()  {
    srand (time(NULL));

    // Initialize SDL2
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        SDL_Log("SDL_Init error: %s", SDL_GetError());
    }

    if(TTF_Init()==-1) {
        SDL_Log("TTF_Init error: %s", TTF_GetError());
    }

    video.init();
    stateMachine = std::make_shared<StateMachine>();

    addStates();
    mainLoop();

}

void Game::addStates() {
    stateMachine->add(std::make_shared<MainMenuState>(stateMachine, video));
    stateMachine->add(std::make_shared<PlayState>(stateMachine, video));
    stateMachine->change(State::MAIN_MENU);
}

void Game::mainLoop() {
    int lastUpdateTime = SDL_GetTicks();

    while (stateMachine->isRunning()) {
        stateMachine->handleEvents();
        const int currentTime = SDL_GetTicks();
        stateMachine->update(currentTime - lastUpdateTime);
        lastUpdateTime = currentTime;
        stateMachine->render();
    }
}

Game::~Game() {
    SDL_Quit();
    TTF_Quit();
}


