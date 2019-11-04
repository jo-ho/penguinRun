#include "sprite.h"


Sprite::Sprite(Video &video,
               const char *fileName,
               int imgX,
               int imgY,
               int imgWidth,
               int imgHeight,
               int initX,
               int initY,
               const SDL_Color *colorKey) {
    spriteTexture = video.loadImage(fileName, colorKey);
    if (!spriteTexture) {
        SDL_Log("video.loadImage error");
    }
    x = initX;
    y = initY;
    srcRect.x = imgX;
    srcRect.y = imgY;
    srcRect.w = imgWidth;
    srcRect.h = imgHeight;
}

Sprite::~Sprite() {
    if (!spriteTexture) {
        SDL_DestroyTexture(spriteTexture);
    }
}


void Sprite::renderSprite(Video &video, int destX, int destY) {
    SDL_Rect destRect;
    destRect.x = destX;
    destRect.y = destY;
    destRect.w = srcRect.w;
    destRect.h = srcRect.h;
    video.renderTexture(spriteTexture, &srcRect, &destRect);
}

int Sprite::getX() {
    return x;
}

int Sprite::getY() {
    return y;
}

void Sprite::setTextureColourMod(SDL_Color colour) {
    SDL_SetTextureColorMod(spriteTexture, colour.r, colour.g, colour.b);

}

void Sprite::setTextureAlphaMod(Uint8 alpha) {
    SDL_SetTextureAlphaMod(spriteTexture, alpha);

}

void Sprite::renderStretchToBackground(Video &video, int destX, int destY) {
    SDL_Rect destRect;
    destRect.x = destX;
    destRect.y = destY;
    destRect.w = video.getScreenSizeW();
    destRect.h = video.getScreenSizeH();
    video.renderTexture(spriteTexture, &srcRect, &destRect);
}

void Sprite::renderSprite(Video &video, int destX, int destY, int destW, int destH) {
    SDL_Rect destRect =  {destX, destY, destW, destH};
    video.renderTexture(spriteTexture, &srcRect, &destRect);
}

