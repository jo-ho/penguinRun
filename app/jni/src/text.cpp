#include "text.h"
#include <SDL.h>
#include <SDL_ttf.h>


const char * FONT_FILE = "akashi.ttf";

Text::Text (int size) {
    font = TTF_OpenFont(FONT_FILE, size);
}


void Text::render(Video  &video, const char * text, SDL_Color color, int destX, int destY) {
    SDL_Texture * texture = video.loadText(font, text, color);
    int w,h;
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    this->w = w;
    this->h = h;
    SDL_Rect destRect;
    destRect.x = destX;
    destRect.y = destY;
    destRect.w = w;
    destRect.h = h;
    video.renderTexture(texture, NULL, &destRect);
    SDL_DestroyTexture(texture);

}

Text::~Text() {
    TTF_CloseFont(font);

}



