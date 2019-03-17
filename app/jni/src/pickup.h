
#ifndef PICKUP_H
#define PICKUP_H


#include "sprite.h"

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


    private:
        int velocityX;
};


#endif
