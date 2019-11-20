#ifndef GAME1_IMAGE_BUTTON_ROW_H
#define GAME1_IMAGE_BUTTON_ROW_H



#include "image_button.h"
#include <vector>
#include <memory>

class ImageButtonRow {
public:
    ImageButtonRow(int x, int y, int w, int h, int buttonSize, int posX);
    ~ImageButtonRow();
    void add(ImageButton * imageButton);
    void render();
    void handleEvent(SDL_Event & event);

private:
    std::vector<ImageButton *> buttons;
    int x;
    int y;
    int w;
    int h;
    int offsetY;
    int numButtons;
    int buttonSize;
};


#endif //GAME1_IMAGE_BUTTON_ROW_H
