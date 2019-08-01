
#ifndef SPRITE_H
#define SPRITE_H

#include "video.h"

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
        void renderStretchToBackground(Video &video, int destX, int destY);
        void setTextureColourMod(SDL_Color colour);
        void setTextureAlphaMod(Uint8 alpha);

        int getX();
        int getY();
    protected:
        SDL_Texture * spriteTexture;
        SDL_Rect srcRect;
        int x;
        int y;
};


#endif //SPRITE_H
