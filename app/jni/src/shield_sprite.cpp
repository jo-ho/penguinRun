#include "shield_sprite.h"

const char * ShieldSprite::SHIELD_SPRITE_FILE_NAME = "spr_shield.png";
const int ShieldSprite::SPRITE_WIDTH = 128;
const int ShieldSprite::SPRITE_HEIGHT = 128;


ShieldSprite::ShieldSprite(Video &video, int initX, int initY) :
        Sprite(video, SHIELD_SPRITE_FILE_NAME, 0, 0, SPRITE_WIDTH, SPRITE_HEIGHT, initX, initY, false){
}
