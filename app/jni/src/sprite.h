
#ifndef SPRITE_H
#define SPRITE_H

#include "Video.h"

class Sprite {
    public:
        Sprite(Video& video,
               const char* fileName,
               int imgX,
               int imgY,
               int imgWidth,
               int imgHeight,
               int initX,
               int initY,
               bool colorKey);
        ~Sprite();
        void renderSprite(Video& video, int destX, int destY);

        int getX();
        int getY();
    protected:
        SDL_Texture * spriteTexture;
        SDL_Rect srcRect;
        int x;
        int y;
};


#endif //SPRITE_H
