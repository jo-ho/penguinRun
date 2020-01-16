//
// Created by User on 2019-10-29.
//

#ifndef GAME1_PAUSE_MENU_H
#define GAME1_PAUSE_MENU_H




#include "sprite.h"
#include "image_button_row.h"

class PauseMenu {
public:
    PauseMenu(Video & video);
    void render();
    void add(ImageButton * imageButton);
    void handleEvent(SDL_Event & event);
private:
    static const int BACKGROUND_WIDTH;
    static const int BACKGROUND_HEIGHT;
    static const int BUTTON_SIZE;

    static const int BUTTON_SPRITE_SIZE;

    std::unique_ptr<Sprite> background;
    std::unique_ptr<ImageButtonRow> buttons;
    Video video;

    int x;
    int y;
    int w;
    int h;

};


#endif //GAME1_PAUSE_MENU_H
