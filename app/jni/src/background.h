#ifndef BACKGROUND_H
#define BACKGROUND_H


#include "video.h"
#include "sprite.h"
#include <SDL.h>

class ScrollableBackground {
public:
    ScrollableBackground(Video & video, const char * fileName, int imgWidth, int imgHeight);
    void render(Video & video);
    void update(int screenSizeW);
private:
    std::unique_ptr<Sprite> sprite;
    int offset;
};


#endif
