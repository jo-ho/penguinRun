#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

#include "sprite.h"


class AnimatedSprite : public Sprite {
    public:
        AnimatedSprite(Video& video,
               const char* fileName,
               int imgX,
               int imgY,
               int imgWidth,
               int imgHeight,
               int initX,
               int initY,
               bool colorKey,
               int numFrames,
               int targetFps);
        void updateSprite(int elapsedTime);

    protected:
        int frameTime;
        int spriteElapsedTime;
        int totalFrames;
        int currentFrame;


};


#endif
