#include "image_button.h"

ImageButton::ImageButton(Video &video,
                         const char * unpressedFileName, const char * pressedFileName,
                         int imgX, int imgY,
                         int imgWidth, int imgHeight,
                         int posX, int posY, bool colorKey)  {
    unpressed = std::unique_ptr<Sprite>(
            new Sprite(video, unpressedFileName, imgX, imgY, imgWidth, imgHeight, posX, posY, colorKey));
    pressed = std::unique_ptr<Sprite>(
            new Sprite(video, pressedFileName, imgX, imgY, imgWidth, imgHeight, posX, posY, colorKey));
    isPressed = false;
    this->video = video;
    this->x = posX;
    this->y = posY;
    this->w = imgWidth;
    this->h = imgHeight;

}

bool ImageButton::handleEvent(SDL_Event &event) {
    float touchPosX = event.tfinger.x * video.getScreenSizeW();
    float touchPosY = event.tfinger.y * video.getScreenSizeH();
    if (event.type == SDL_FINGERDOWN) {

        isPressed = (touchPosX >= x && touchPosX <= (x + w)) &&
                    (touchPosY >= y && touchPosY <= (y + h));
        return false;
    } else if (event.type == SDL_FINGERUP) {

        isPressed = false;
        return (touchPosX >= x && touchPosX <= (x + w)) &&
               (touchPosY >= y && touchPosY <= (y + h));
    }
    return false;
}

void ImageButton::render() {

    if (isPressed) {
        pressed->renderSprite(video, x, y);
    } else unpressed->renderSprite(video, x, y);
}


