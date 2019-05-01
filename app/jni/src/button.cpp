#include "Button.h"

const int Button::BUTTON_WIDTH = 382;
const int Button::BUTTON_HEIGHT = 192;

Button::Button(Video &video,
               const char *fileName,
               int imgX,
               int imgY,
               int imgWidth,
               int imgHeight,
               int initX,
               int initY,
               bool colorKey) : Sprite(video, fileName, imgX ,imgY , imgWidth, imgHeight, initX, initY, colorKey) {

}

bool Button::checkTouch(float touchPosX, float touchPosY) {

    return (touchPosX >= x && touchPosX <= (x + srcRect.w)) &&
           (touchPosY >= y && touchPosY <= (y + srcRect.h));
}