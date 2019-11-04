#include "pause_menu.h"

const int PauseMenu::BACKGROUND_WIDTH = 2102;
const int PauseMenu::BACKGROUND_HEIGHT = 2121;

PauseMenu::PauseMenu(Video &video) {
    background = std::unique_ptr<Sprite>(new Sprite(
            video, "gui/frames/paused.png",
            0, 0,
            BACKGROUND_WIDTH, BACKGROUND_HEIGHT,
            0, 0));
    this->video = video;
}

void PauseMenu::render() {
    background->renderSprite(video, (video.getScreenSizeW() -  BACKGROUND_WIDTH / 4) /2, (video.getScreenSizeH() -  BACKGROUND_HEIGHT / 4) /2 , BACKGROUND_WIDTH / 4, BACKGROUND_HEIGHT / 4);

}
