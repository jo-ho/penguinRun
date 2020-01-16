#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>


#include "video.h"




Video::Video() {
    renderer = NULL;
    window = NULL;
    screenSize = {0, 0, 0, 0};
}

void Video::init() {
    // Create window and renderer
    SDL_GetCurrentDisplayMode(0, &displayMode);
    window = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, displayMode.w, displayMode.h, SDL_WINDOW_SHOWN);
    screenSize = {0, 0, displayMode.w, displayMode.h};

    if (!window) {
        SDL_Log("SDL_CreateWindow error: %s", SDL_GetError());
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (!renderer) {
        SDL_Log("SDL_CreateRenderer error: %s", SDL_GetError());
    }
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);


    // Initialize SDL2_image
    int flags=IMG_INIT_JPG|IMG_INIT_PNG;
    int initted=IMG_Init(flags);
    if ((initted&flags) != flags) {
        SDL_Log("IMG_Init: Failed to init required jpg and png support!\n");
        SDL_Log("IMG_Init: %s\n", IMG_GetError());
    }


}

Video::~Video() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    IMG_Quit();
}

void Video::clear() {
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer);

}

void Video::present() {
    SDL_RenderPresent(renderer);
}

// Load image from file and convert to SDL_Texture
SDL_Texture * Video::loadImage(const char * fileName, const SDL_Color * colorKey) {
    SDL_Surface * tempSurface = IMG_Load(fileName);
    if (!tempSurface) {
        SDL_Log("IMG_Load error: %s", IMG_GetError());
    }
    if (colorKey) {
        SDL_SetColorKey(tempSurface, SDL_TRUE, SDL_MapRGB(tempSurface->format, colorKey->r, colorKey->g, colorKey->b));
    }
    SDL_Texture * newTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    if (!newTexture) {
        SDL_Log("SDL_CreateTextureFromSurface error: %s", SDL_GetError());
    }
    SDL_FreeSurface(tempSurface);
    return newTexture;

}

void Video::renderTexture(SDL_Texture *targetTexture, SDL_Rect * srcRect, SDL_Rect * destRect) {
    SDL_RenderCopy(renderer, targetTexture, srcRect, destRect);
}

int Video::getScreenSizeH() {
    return screenSize.h;
}

int Video::getScreenSizeW() {
    return  screenSize.w;
}

SDL_Texture *Video::loadText(TTF_Font * font, const char *text, SDL_Color color) {
    SDL_Surface * surface = TTF_RenderText_Solid(font, text, color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

void Video::renderRect(const SDL_Rect *srcRect) {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawRect(renderer, srcRect);

}

