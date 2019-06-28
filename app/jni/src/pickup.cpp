#include "pickup.h"
#include <stdlib.h>
#include <time.h>

const int Pickup::PICKUP_WIDTH = 64;
const int Pickup::PICKUP_HEIGHT = 64;

const static int VELOCITY_MIN = 5;
const static int VELOCITY_OFFSET = 5;

Pickup::Pickup(Video &video,
               const char *fileName,
               int imgX,
               int imgY,
               int imgWidth,
               int imgHeight,
               int initX,
               int initY,
               bool colorKey) :
        Sprite(video, fileName, imgX ,imgY , imgWidth, imgHeight, initX, initY, colorKey) {
    // Range = [VELOCITY_MIN, VELOCITY_MIN + VELOCITY_OFFSET]
    velocityX = rand() % (VELOCITY_OFFSET + 1) + VELOCITY_MIN;
}

void Pickup::move() {
    x -= velocityX;
}

SDL_Rect Pickup::getCollider() {
    SDL_Rect collider;
    collider.x = x;
    collider.y = y;
    collider.w = PICKUP_WIDTH;
    collider.h = PICKUP_HEIGHT;
    return collider;
}



