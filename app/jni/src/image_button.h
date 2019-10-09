#ifndef GAME1_IMAGE_BUTTON_H
#define GAME1_IMAGE_BUTTON_H


#include "sprite.h"
#include <memory>
#include <SDL_events.h>

class ImageButton {
public:
    ImageButton(Video &video,
            const char * unpressedFileName, const char * pressedFileName,
            int imgX, int imgY,
            int imgWidth, int imgHeight,
            int posX, int posY, bool colorKey);
    bool handleEvent(SDL_Event & event);
    void render();
    void setX(int x);
    void setY(int y);


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
