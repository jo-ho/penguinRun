#include "image_button.h"
#include "collision.h"
#include "asset_manager.h"

ImageButton::ImageButton(Video &video, const char *unpressedName, const char * pressedName,
        int posX, int posY,
        std::function<void()> callback) {
    unpressed = AssetManager::Get()->GetSprite(unpressedName);
    pressed = AssetManager::Get()->GetSprite(pressedName);
    isPressed = false;
    this->callback = callback;
    this->video = video;
    this->x = posX;
    this->y = posY;

}

bool ImageButton::handleEvent(SDL_Event &event, int w, int h) {
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

void ImageButton::render(int w, int h) {

    if (isPressed) {
        pressed->renderSprite(video, x, y, w, h);
    } else unpressed->renderSprite(video, x, y, w, h);
}

void ImageButton::setY(int y) {
    this->y = y;
}

void ImageButton::setX(int x) {
    this->x = x;

}

int ImageButton::getX() {
    return x;
}

int ImageButton::getY() {
    return y;
}


