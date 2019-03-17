#include "player.h"
#include "../SDL2/include/SDL_rect.h"

const int Player::PLAYER_WIDTH = 64;
const int Player::PLAYER_HEIGHT = 144;
const int Player::NUM_FRAMES = 3;
const int Player::TARGET_FPS = 10;


Player::Player(Video &video,
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
        AnimatedSprite(video, fileName, imgX, imgY, imgWidth, imgHeight, initX, initY, colorKey, numFrames, targetFps) {
    playerVelY = 0;

}

void Player::reset() {
    playerVelY = 0;
}

void Player::updatePos(int screenSizeY) {
    // Cap velocity
    if (playerVelY > PLAYER_VELOCITY || playerVelY < -PLAYER_VELOCITY) playerVelY = (playerVelY > 0) ? PLAYER_VELOCITY : -PLAYER_VELOCITY;

    y += playerVelY;
    // Cap position
    if (y > screenSizeY - srcRect.h || y < 0) y = (y < 0) ? 0 : screenSizeY - srcRect.h;

}

void Player::startMoveDown() {
    playerVelY = PLAYER_VELOCITY;
}

void Player::startMoveUp() {
    playerVelY = -PLAYER_VELOCITY;
}


void Player::stopMove() {
    playerVelY = 0;
}


SDL_Rect Player::getCollider() {
    SDL_Rect collider;
    collider.x = x;
    collider.y = y;
    collider.w = PLAYER_WIDTH;
    collider.h = PLAYER_HEIGHT;
    return collider;
}


bool Player::checkCollision(SDL_Rect collider) {
    SDL_Rect playerCollider = getCollider();

    return playerCollider.x < collider.x + collider.w &&
           playerCollider.y < collider.y + collider.h &&
           collider.x < playerCollider.x + playerCollider.w &&
           collider.y < playerCollider.y + playerCollider.h;

}



