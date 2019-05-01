
#ifndef PLAYER_H
#define PLAYER_H


#include "AnimatedSprite.h"

const static int PLAYER_VELOCITY = 10;

class Player : public AnimatedSprite {
    public:

        Player(Video &video);
        void reset();
        void updatePos(int screenSizeY);
        void startMoveDown();
        void startMoveUp();
        void stopMove();

        bool checkCollision(SDL_Rect collider);


    private:
        const static int PLAYER_WIDTH;
        const static int PLAYER_HEIGHT;
        const static int NUM_FRAMES;
        const static int TARGET_FPS;
        const static char * SPRITE_FILE_NAME;
        int playerVelY;
        SDL_Rect getCollider();

};


#endif
