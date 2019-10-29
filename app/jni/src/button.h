#ifndef BUTTON_H
#define BUTTON_H


#include "sprite.h"

class Button : public Sprite {
    public:
        const static int BUTTON_WIDTH;
        const static int BUTTON_HEIGHT;

        Button(Video &video,
               const char *fileName,
               int imgX,
               int imgY,
               int imgWidth,
               int imgHeight,
               int initX,
               int initY,
               const SDL_Color *colorKey = nullptr);
        bool checkTouch(float touchPosX, float touchPosY);
};


#endif
