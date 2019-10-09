#ifndef GAME1_IMAGE_BUTTON_ROW_H
#define GAME1_IMAGE_BUTTON_ROW_H



#include "image_button.h"
#include <vector>
#include <memory>

class ImageButtonRow {
public:
    ImageButtonRow(int x, int y, int w, int h, int buttonSize);
    ~ImageButtonRow();
    void add(ImageButton * imageButton);
    void render();

private:
    std::vector<ImageButton *> buttons;
    int x;
    int y;
    int w;
    int h;
    int numButtons;
    int buttonSize;
};


#endif //GAME1_IMAGE_BUTTON_ROW_H
