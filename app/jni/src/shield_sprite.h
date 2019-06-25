#ifndef SHIELD_SPRITE_H
#define SHIELD_SPRITE_H


#include "video.h"
#include "sprite.h"

class ShieldSprite : public Sprite {

public:
    ShieldSprite(Video & video, int initX, int initY);

private:
    const static char * SHIELD_SPRITE_FILE_NAME;
public:
    const static int SPRITE_WIDTH;
    const static int SPRITE_HEIGHT;
};


#endif
