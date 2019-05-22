
#ifndef PLAYER_H
#define PLAYER_H


#include "animated_sprite.h"

const static int DEFAULT_VELOCITY = 10;
const static int SLOW_VELOCITY = 5;
const static int FAST_VELOCITY = 20;

enum MoveState { MOVING_UP, MOVING_DOWN, STOPPED };
enum SpeedState {NORMAL, SLOWED, SPED_UP};


class Player : public AnimatedSprite {
    public:

        Player(Video &video);
        void updatePos(int screenSizeY);
        SpeedState getSpeedState();
        void setSpeedState(SpeedState newState);
        void setMoveState(MoveState newState);
        void increaseScore(int num);
        int getScore();
        bool checkCollision(SDL_Rect collider);


    private:
        const static int PLAYER_WIDTH;
        const static int PLAYER_HEIGHT;
        const static int NUM_FRAMES;
        const static int TARGET_FPS;
        const static char * SPRITE_FILE_NAME;
        MoveState moveState;
        SpeedState speedState;

        int playerVelY;
        int score;
        SDL_Rect getCollider();

};


#endif
