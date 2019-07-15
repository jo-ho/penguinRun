#ifndef PICKUP_H
#define PICKUP_H

#include <memory>
#include "sprite.h"
#include "player.h"

class Pickup : public Sprite {
    public:
        Pickup(Video& video,
        const char* fileName,
        int imgX,
        int imgY,
        int imgWidth,
        int imgHeight,
        int initX,
        int initY,
        bool colorKey);
        void move(int screenHeight);
        SDL_Rect getCollider();
        virtual void activateAction(std::unique_ptr<Player> &player) = 0;
        const static int PICKUP_WIDTH;
        const static int PICKUP_HEIGHT;


    private:
        int velocityX;
        int velocityY;

};


#endif
