#include "pause_menu.h"
#include "colour.h"
#include "asset_manager.h"

const int PauseMenu::BACKGROUND_WIDTH = 2102;
const int PauseMenu::BACKGROUND_HEIGHT = 2121;
const int PauseMenu::BUTTON_SIZE = 100;



PauseMenu::PauseMenu(Video &video) {
    background = AssetManager::Get()->GetSprite("paused_frame");
    this->video = video;
    x = (video.getScreenSizeW() -  BACKGROUND_WIDTH / 4) /2;
    y = (video.getScreenSizeH() -  BACKGROUND_HEIGHT / 4) /2;
    w = BACKGROUND_WIDTH / 4;
    h = BACKGROUND_HEIGHT / 4;

    buttons = std::unique_ptr<ImageButtonRow>(new ImageButtonRow(x, y, w, h, BUTTON_SIZE, h - (w / 3)));
    headline = AssetManager::Get()->GetSprite("paused_hl");
}

void PauseMenu::render() {
    background->renderSprite(video, x, y, w, h);
    headline->renderSprite(video,
            (x + w  / 2) - (HEADLINE_SIZE_W / 2)  , y + h / 4,
            HEADLINE_SIZE_W, HEADLINE_SIZE_H);
    buttons->render();

}

void PauseMenu::add(ImageButton * imageButton) {
    buttons->add(imageButton);
}

void PauseMenu::handleEvent(SDL_Event &event) {
    buttons->handleEvent(event);
}
