#ifndef PICKUP_H
#define PICKUP_H

#include <memory>
#include "sprite.h"
#include "player.h"

class Pickup {
    public:
        Pickup(const char *textureName, int initX, int initY);
        void move(int screenHeight);
        void render(Video & video);
        SDL_Rect getCollider();
        int getX();
        int getY();
        virtual void activateAction(std::unique_ptr<Player> &player) = 0;
        const static int PICKUP_WIDTH;
        const static int PICKUP_HEIGHT;


    private:
        Sprite * sprite;
        int velocityX;
        int velocityY;
        int x;
        int y;

};


#endif
