#ifndef BACKGROUND_H
#define BACKGROUND_H


#include "video.h"
#include <SDL.h>

class Background {
public:
    Background(Video & video, const char * fileName);
    void render(Video & video);
private:
    SDL_Texture * texture;
};


#endif
