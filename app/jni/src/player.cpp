#include "player.h"
#include "../SDL2/include/SDL_rect.h"
#include <sstream>

const int Player::SPRITE_SHEET_WIDTH = 90;
const int Player::SPRITE_SHEET_HEIGHT = 208;
const int Player::TILE_WIDTH = 30;
const int Player::TILE_HEIGHT = 52;
const int Player::NUM_FRAMES = 3;
const int Player::TARGET_FPS = 10;
const char * Player::SPRITE_FILE_NAME = "penguin-gray_new.png";




Player::Player(Video &video) {
    playerVelY = DEFAULT_VELOCITY;
    moveState = STOPPED;
    speedState = NORMAL;
    score = 0;
    damagedState = UNHURT;
    initSprites(video);
}

void Player::initSprites(Video & video) {
    for (int i = MOVING_UP; i <= MOVING_DOWN; i++){
        MoveState state = static_cast<MoveState>(i);
        sprites[state] = std::unique_ptr<AnimatedSprite>(new AnimatedSprite(video, SPRITE_FILE_NAME,
                                                                            0, TILE_HEIGHT * i,
                                                                            TILE_WIDTH, TILE_HEIGHT,
                                                                            0, 0,
                                                                            false, NUM_FRAMES, TARGET_FPS));
    }
}

//TODO merge with update()
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

    if (y > screenSizeY - TILE_HEIGHT || y < 0) y = (y < 0) ? 0 : screenSizeY - TILE_HEIGHT;
}



SDL_Rect Player::getCollider() {
    SDL_Rect collider;
    collider.x = 0;
    collider.y = y;
    collider.w = TILE_WIDTH;
    collider.h = TILE_HEIGHT;
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

void Player::render(Video &video, int x, int y) {
    sprites[moveState]->renderSprite(video, x , y);
}

void Player::update(int elapsedTime) {
    sprites[moveState]->updateSprite(elapsedTime);
}

int Player::getY() {
    return y;
}







