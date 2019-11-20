#include "image_button_row.h"

`ImageButtonRow::ImageButtonRow(int x, int y, int w, int h, int buttonSize, int offsetY) {
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->buttonSize = buttonSize;
    this->offsetY = offsetY;
    numButtons = 0;

}

void ImageButtonRow::add(ImageButton *imageButton) {
    numButtons++;
    buttons.push_back(imageButton);


    int i = 0;
    for (auto &  b : buttons) {
        float posX = x + ((i + 1.0f) / (numButtons + 1.0f)) * w;
        posX -= buttonSize / 2.0f;
        b->setX(static_cast<int>(posX));
        b->setY(y + offsetY - (buttonSize/ 2));
        i++;

    }
}

void ImageButtonRow::render() {
    for (auto & b : buttons) {
        b->render(buttonSize, buttonSize);
    }

}

ImageButtonRow::~ImageButtonRow() {
    for (auto & b : buttons) {
        delete b;
    }

}

void ImageButtonRow::handleEvent(SDL_Event & event) {
    for (auto & b : buttons) {
        b->handleEvent(event);
    }

}
