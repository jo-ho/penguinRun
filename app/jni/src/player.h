
#ifndef PLAYER_H
#define PLAYER_H


#include "animated_sprite.h"

const static int PLAYER_VELOCITY = 10;

class Player : public AnimatedSprite {
    public:

        Player(Video &video);
        void reset();
        void updatePos(int screenSizeY);
        void startMoveDown();
        void startMoveUp();
        void stopMove();

        void increaseScore(int num);

        bool checkCollision(SDL_Rect collider);
        int getScore();


    private:
        const static int PLAYER_WIDTH;
        const static int PLAYER_HEIGHT;
        const static int NUM_FRAMES;
        const static int TARGET_FPS;
        const static char * SPRITE_FILE_NAME;
        int playerVelY;
        int score;
        SDL_Rect getCollider();

};


#endif
