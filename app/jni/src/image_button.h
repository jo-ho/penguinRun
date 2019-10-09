//
// Created by User on 2019-10-07.
//

#ifndef GAME1_IMAGE_BUTTON_H
#define GAME1_IMAGE_BUTTON_H


#include "sprite.h"
#include <memory>

class ImageButton {
public:
    ImageButton(Video &video,
            const char * unpressedFileName, const char * pressedFileName,
            int imgX, int imgY,
            int imgWidth, int imgHeight,
            int posX, int posY, bool colorKey);
    bool handleEvent(SDL_Event & event);
    void render();


private:
    std::unique_ptr<Sprite> unpressed;
    std::unique_ptr<Sprite> pressed;
    Video video;
    int x;
    int y;
    int w;
    int h;
    bool isPressed;
};


#endif //GAME1_IMAGE_BUTTON_H
