#include "image_button.h"
#include "collision.h"

ImageButton::ImageButton(Video &video, const char *unpressedFileName, const char *pressedFileName,
                         int imgX,
                         int imgY, int imgWidth, int imgHeight, int posX, int posY,
                         std::function<void()> callback, const SDL_Color *colorKey) {
    unpressed = std::unique_ptr<Sprite>(
            new Sprite(video, unpressedFileName, imgX, imgY, imgWidth, imgHeight, posX, posY, colorKey));
    pressed = std::unique_ptr<Sprite>(
            new Sprite(video, pressedFileName, imgX, imgY, imgWidth, imgHeight, posX, posY, colorKey));
    isPressed = false;
    this->callback = callback;
    this->video = video;
    this->x = posX;
    this->y = posY;
    this->w = imgWidth;
    this->h = imgHeight;

}

bool ImageButton::handleEvent(SDL_Event &event) {
    float touchPosX = event.tfinger.x * video.getScreenSizeW();
    float touchPosY = event.tfinger.y * video.getScreenSizeH();
    bool fingerOnButton = Collision::PointInRect(touchPosX, touchPosY, {x,y,w,h});
    if (event.type == SDL_FINGERDOWN) {

        isPressed = fingerOnButton;
        return false;
    } else if (event.type == SDL_FINGERUP) {

        isPressed = false;
        if (fingerOnButton) {
            callback();
        }
        return fingerOnButton;
    }
    return false;
}

void ImageButton::render() {

    if (isPressed) {
        pressed->renderSprite(video, x, y);
    } else unpressed->renderSprite(video, x, y);
}

void ImageButton::setY(int y) {
    this->y = y;
}

void ImageButton::setX(int x) {
    this->x = x;

}

SDL_Rect ImageButton::getButtonArea() {
    return {x,y,w,h};
}


