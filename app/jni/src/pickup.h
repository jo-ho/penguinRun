#ifndef PICKUP_H
#define PICKUP_H


#include "Sprite.h"

class Pickup : public Sprite {
    public:
        Pickup(Video& video,
        const char* fileName,
        int imgX,
        int imgY,
        int imgWidth,
        int imgHeight,
        int initX,
        int initY,
        bool colorKey);
        void move();
        SDL_Rect getCollider();
        const static int PICKUP_WIDTH;
        const static int PICKUP_HEIGHT;


    private:
        int velocityX;

};


#endif
