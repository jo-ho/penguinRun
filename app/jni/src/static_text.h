#ifndef GAME1_STATIC_TEXT_H
#define GAME1_STATIC_TEXT_H


#include <SDL.h>
#include "video.h"

class StaticText {
public:
    StaticText(Video & video, const char * fontName, const char * text, SDL_Color color);
    void render(Video & video, int destX, int destY);
    ~StaticText();

    int w,h;

private:
    SDL_Texture * texture;
};


#endif //GAME1_STATIC_TEXT_H
