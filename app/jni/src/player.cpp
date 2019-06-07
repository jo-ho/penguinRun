#include "player.h"
#include "../SDL2/include/SDL_rect.h"
#include <sstream>

const int Player::SPRITE_SHEET_WIDTH = 144;
const int Player::SPRITE_SHEET_HEIGHT = 64;
const int Player::NUM_FRAMES = 3;
const int Player::TARGET_FPS = 10;
const char * Player::SPRITE_FILE_NAME = "penguin-gray.png";




Player::Player(Video &video) :
        AnimatedSprite(
                video, SPRITE_FILE_NAME,
                0, SPRITE_SHEET_HEIGHT,
                SPRITE_SHEET_WIDTH, SPRITE_SHEET_HEIGHT,
                0,
                video.getScreenSizeH() / 2 - SPRITE_SHEET_HEIGHT / 2,
                false,
                NUM_FRAMES, TARGET_FPS) {
    playerVelY = DEFAULT_VELOCITY;
    moveState = STOPPED;
    speedState = NORMAL;
    score = 0;
    damagedState = UNHURT;
}

void Player::updatePos(int screenSizeY) {

    switch (speedState) {
        case NORMAL:
            playerVelY = DEFAULT_VELOCITY;
            break;
        case SLOWED:
            playerVelY = SLOW_VELOCITY;
            break;
        case SPED_UP:
            playerVelY = FAST_VELOCITY;
            break;
    }

    switch (moveState) {
        case MOVING_DOWN:
            y += playerVelY;
            break;
        case MOVING_UP:
            y -= playerVelY;
            break;
        case STOPPED:
            y += 0;
            break;
    }


    if (y > screenSizeY - srcRect.h || y < 0) y = (y < 0) ? 0 : screenSizeY - srcRect.h;

}



SDL_Rect Player::getCollider() {
    SDL_Rect collider;
    collider.x = x;
    collider.y = y;
    collider.w = SPRITE_SHEET_WIDTH / totalFrames;
    collider.h = SPRITE_SHEET_HEIGHT;
    return collider;
}


bool Player::checkCollision(SDL_Rect collider) {
    SDL_Rect playerCollider = getCollider();

    return playerCollider.x < collider.x + collider.w &&
           playerCollider.y < collider.y + collider.h &&
           collider.x < playerCollider.x + playerCollider.w &&
           collider.y < playerCollider.y + playerCollider.h;

}

void Player::increaseScore(int num) {
    score += num;
}

int Player::getScore() {
    return score;
}

SpeedState Player::getSpeedState() {
    return speedState;
}


void Player::setSpeedState(SpeedState newState) {
    speedState = newState;
}

void Player::setMoveState(MoveState newState) {
    moveState = newState;

}

bool Player::isDead() {
    return damagedState == DEAD;
}

void Player::setDamagedState(DamagedState newState){
    damagedState = newState;
}

DamagedState Player::getDamagedState() {
    return damagedState;
}






