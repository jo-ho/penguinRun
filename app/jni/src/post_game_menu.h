//
// Created by User on 2020-02-27.
//

#ifndef GAME1_POST_GAME_MENU_H
#define GAME1_POST_GAME_MENU_H


static const int GAME_OVER_OFFSET_Y = 66;




#include "sprite.h"
#include "image_button_row.h"
#include "text.h"
#include "static_text.h"
#include "colour.h"

class PostGameMenu {
public:
    PostGameMenu(Video & video);
    void render(int score);
    void add(ImageButton * imageButton);
    void handleEvent(SDL_Event & event);
private:
    static const int BUTTON_SIZE = 150;

    Sprite * background;
    Video video;
    int x, y, w, h;
    std::unique_ptr<StaticText> gameOver;
    std::unique_ptr<StaticText> finalScoreTitle;
    Text finalScore = Text("akashi60");
    std::unique_ptr<ImageButtonRow> buttons;

};

#endif //GAME1_POST_GAME_MENU_H
