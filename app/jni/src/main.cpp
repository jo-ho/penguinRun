#include <SDL.h>


#include "game.h"

int main( int argc, char* args[] ){
    // Initialize SDL2
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        SDL_Log("SDL_Init error: %s", SDL_GetError());
    }

    if(TTF_Init()==-1) {
        SDL_Log("TTF_Init error: %s", TTF_GetError());
    }

    Game game;
    return 0;
}