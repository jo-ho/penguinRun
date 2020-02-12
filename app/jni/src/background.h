#ifndef BACKGROUND_H
#define BACKGROUND_H


#include "video.h"
#include "sprite.h"
#include <SDL.h>

class ScrollableBackground {
public:
    ScrollableBackground(const char * name);
    void render(Video & video);
    void update(int screenSizeW);
private:
    Sprite * sprite;
    int offset;
};


#endif
