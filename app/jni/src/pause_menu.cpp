#include "pause_menu.h"
#include "colour.h"

const int PauseMenu::BACKGROUND_WIDTH = 2102;
const int PauseMenu::BACKGROUND_HEIGHT = 2121;

PauseMenu::PauseMenu(Video &video) {
    background = std::unique_ptr<Sprite>(new Sprite(
            video, "gui/frames/paused.png",
            0, 0,
            BACKGROUND_WIDTH, BACKGROUND_HEIGHT,
            0, 0));
    this->video = video;
    x = (video.getScreenSizeW() -  BACKGROUND_WIDTH / 4) /2;
    y = (video.getScreenSizeH() -  BACKGROUND_HEIGHT / 4) /2;
    w = BACKGROUND_WIDTH / 4;
    h = BACKGROUND_HEIGHT / 4;

    buttons = std::unique_ptr<ImageButtonRow>(new ImageButtonRow(x, y, w, h, BUTTON_SIZE, h - (w / 3)));
    buttons->add(new ImageButton(
            video, "gui/buttons/normal/play.png", "gui/buttons/click/play.png",
            0, 0, BUTTON_SPRITE_SIZE, BUTTON_SPRITE_SIZE,
            0, 0, []() {}, &Colour::black));
    buttons->add(new ImageButton(
            video, "gui/buttons/normal/home.png", "gui/buttons/click/home.png",
            0, 0, BUTTON_SPRITE_SIZE, BUTTON_SPRITE_SIZE,
            0, 0, []() {}, &Colour::black));
}

void PauseMenu::render() {
    background->renderSprite(video, x, y, w, h);
    buttons->render();

}
