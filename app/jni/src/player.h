
#ifndef PLAYER_H
#define PLAYER_H


#include "animatedsprite.h"

const static int PLAYER_VELOCITY = 10;

class Player : public AnimatedSprite {
    public:
        const static int PLAYER_WIDTH;
        const static int PLAYER_HEIGHT;
        const static int NUM_FRAMES;
        const static int TARGET_FPS;
        Player(Video &video,
               const char *fileName,
               int imgX,
               int imgY,
               int imgWidth,
               int imgHeight,
               int initX,
               int initY,
               bool colorKey,
               int numFrames,
               int targetFps);
        void reset();
        void updatePos(int screenSizeY);
        void startMoveDown();
        void startMoveUp();
        void stopMove();

        bool checkCollision(SDL_Rect collider);



    private:
        int playerVelY;
        SDL_Rect getCollider();

};


#endif
