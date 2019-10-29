#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

#include "sprite.h"


class AnimatedSprite : public Sprite {
    public:
        AnimatedSprite(Video &video, const char *fileName, int imgX, int imgY, int imgWidth,
                       int imgHeight, int initX, int initY, int numFrames, int targetFps,
                       const SDL_Color *colorKey = nullptr);
        void updateSprite(int elapsedTime);
        int getNumCompletedLoops();

    protected:
        int frameTime;
        int spriteElapsedTime;
        int totalFrames;
        int currentFrame;

private:
    int numCompletedLoops;

};


#endif
