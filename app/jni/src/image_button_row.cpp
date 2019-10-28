#include "image_button_row.h"

ImageButtonRow::ImageButtonRow(int x, int y, int w, int h, int buttonSize) {
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->buttonSize = buttonSize;
    numButtons = 0;

}

void ImageButtonRow::add(ImageButton *imageButton) {
    numButtons++;
    buttons.push_back(imageButton);


    int i = 0;
    for (auto &  b : buttons) {
        float posX = ((i + 1.0f) / (numButtons + 1.0f)) * w;
        posX -= buttonSize / 2.0f;
        b->setX(static_cast<int>(posX));
        i++;

    }
}

void ImageButtonRow::render() {
    for (auto & b : buttons) {
        b->render();
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
