#include "player.h"
#include <SDL.h>
#include "shield_sprite.h"
#include <sstream>
#include "colour.h"

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
    x = ShieldSprite::SPRITE_WIDTH / 2;
    y = video.getScreenSizeH() / 2 - TILE_HEIGHT / 2;
    initSprites(video);
}

void Player::initSprites(Video & video) {
    for (int i = MOVING_UP; i <= MOVING_DOWN; i++){
        MoveState state = static_cast<MoveState>(i);
        sprites[state] = std::unique_ptr<AnimatedSprite>(new AnimatedSprite(video, SPRITE_FILE_NAME,
                                                                            0, TILE_HEIGHT * i,
                                                                            TILE_WIDTH, TILE_HEIGHT,
                                                                            0, 0, true, NUM_FRAMES, TARGET_FPS));
    }
    shieldSprite = std::unique_ptr<Sprite>(new ShieldSprite(video, x, y));
}

void Player::update(int screenSizeY, int elapsedTime) {

    switch (speedState) {
        case NORMAL:
            playerVelY = DEFAULT_VELOCITY;
            sprites[moveState]->setTextureColourMod(Colour::white);
            break;
        case SLOWED:
            playerVelY = SLOW_VELOCITY;
            sprites[moveState]->setTextureColourMod(Colour::blue);
            break;
        case SPED_UP:
            playerVelY = FAST_VELOCITY;
            sprites[moveState]->setTextureColourMod(Colour::purple);
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

    // Cap player position to screen
    if (y > screenSizeY - TILE_HEIGHT || y < 0) y = (y < 0) ? 0 : screenSizeY - TILE_HEIGHT;

    sprites[moveState]->updateSprite(elapsedTime);
}



SDL_Rect Player::getCollider() {
    SDL_Rect collider;
    collider.x = x;
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

void Player::setDamagedState(DamagedState newState){
    damagedState = newState;
}

DamagedState Player::getDamagedState() {
    return damagedState;
}

void Player::render(Video &video) {
    if (damagedState == SHIELDED) {
        int playerCenterX = x + (TILE_WIDTH / 2);
        int playerCenterY = y + (TILE_HEIGHT / 2);
        int shieldX = playerCenterX - (ShieldSprite::SPRITE_WIDTH / 2);
        int shieldY = playerCenterY - (ShieldSprite::SPRITE_HEIGHT / 2);
        shieldSprite->renderSprite(video, shieldX, shieldY);
    }
    sprites[moveState]->renderSprite(video, x , y);
}

int Player::getX() {
    return x;
}

int Player::getY() {
    return y;
}







