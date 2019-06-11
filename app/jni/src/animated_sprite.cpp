#include "animated_sprite.h"

AnimatedSprite::AnimatedSprite(Video &video,
                               const char *fileName,
                               int imgX,
                               int imgY,
                               int imgWidth,
                               int imgHeight,
                               int initX,
                               int initY,
                               bool colorKey,
                               int numFrames,
                               int targetFps) :
        Sprite(video, fileName, imgX ,imgY , imgWidth, imgHeight, initX, initY, colorKey) {
    frameTime = 1000 / targetFps;
    spriteElapsedTime = 0;
    totalFrames = numFrames;
    currentFrame = 0;
}

void AnimatedSprite::updateSprite(int elapsedTime) {
    spriteElapsedTime += elapsedTime;
    if (spriteElapsedTime > frameTime) {
        spriteElapsedTime = 0;
        if (currentFrame >= totalFrames - 1) {
            currentFrame = 0;

        } else {
            currentFrame++;
        }

    }
    srcRect.x = currentFrame * srcRect.w;
}
