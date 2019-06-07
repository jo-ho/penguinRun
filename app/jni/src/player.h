
#ifndef PLAYER_H
#define PLAYER_H


#include "animated_sprite.h"

const static int DEFAULT_VELOCITY = 10;
const static int SLOW_VELOCITY = 5;
const static int FAST_VELOCITY = 20;

enum MoveState { MOVING_UP, MOVING_DOWN, STOPPED };
enum SpeedState {NORMAL, SLOWED, SPED_UP};
enum DamagedState {UNHURT ,SHIELDED, DEAD};


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
        bool isDead();
        void setDamagedState(DamagedState newState);
        DamagedState getDamagedState();




private:
        const static int SPRITE_SHEET_WIDTH;
        const static int SPRITE_SHEET_HEIGHT;
        const static int NUM_FRAMES;
        const static int TARGET_FPS;
        const static char * SPRITE_FILE_NAME;
        MoveState moveState;
        SpeedState speedState;
        DamagedState damagedState;

        int playerVelY;
        int score;
        SDL_Rect getCollider();



};


#endif
