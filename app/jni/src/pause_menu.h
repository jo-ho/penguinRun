//
// Created by User on 2019-10-29.
//

#ifndef GAME1_PAUSE_MENU_H
#define GAME1_PAUSE_MENU_H




#include "sprite.h"

class PauseMenu {
public:
    PauseMenu(Video & video);
    void render();
private:
    static const int BACKGROUND_WIDTH;
    static const int BACKGROUND_HEIGHT;

    std::unique_ptr<Sprite> background;
    Video video;

};


#endif //GAME1_PAUSE_MENU_H
