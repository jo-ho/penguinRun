#ifndef GAME1_IMAGE_BUTTON_H
#define GAME1_IMAGE_BUTTON_H


#include "sprite.h"
#include <memory>
#include <SDL_events.h>
#include <functional>

class ImageButton {
public:
    ImageButton(Video &video, const char *unpressedName, const char *pressedName,
                int posX, int posY,
                std::function<void()> callback);
    bool handleEvent(SDL_Event & event, int w, int h);
    void render(int w, int h);
    void setX(int x);
    void setY(int y);
    int getX();
    int getY();


private:
    Sprite * unpressed;
    Sprite * pressed;
    Video video;
    int x;
    int y;
    bool isPressed;
    std::function<void()> callback;
};


#endif //GAME1_IMAGE_BUTTON_H
