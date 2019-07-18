#ifndef DEATH_ANIMATION_H
#define DEATH_ANIMATION_H


#include "video.h"
#include "animated_sprite.h"

class DeathAnimation : public AnimatedSprite {
public:
    DeathAnimation(Video & video);

private:
    static const int NUM_FRAMES;
    static const int TARGET_FPS;
};


#endif //DEATH_ANIMATION_H
