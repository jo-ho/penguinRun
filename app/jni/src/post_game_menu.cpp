//
// Created by User on 2020-02-27.
//

#include "post_game_menu.h"
#include "sprite.h"
#include "asset_manager.h"
#include "colour.h"

PostGameMenu::PostGameMenu(Video & video) {
    background = AssetManager::Get()->GetSprite("post_game_frame");
    this->video = video;

    gameOver = std::unique_ptr<StaticText>(new StaticText(video, "akashi48", "Game over", Colour::black));
    finalScoreTitle = std::unique_ptr<StaticText>(new StaticText(video, "akashi36", "Final score:", Colour::black));

    x = (video.getScreenSizeW() -  AssetManager::FRAME_W / 2) /2;
    y = (video.getScreenSizeH() -  AssetManager::POST_GAME_FRAME_H / 2) /2;
    w = AssetManager::FRAME_W  / 2;
    h = AssetManager::POST_GAME_FRAME_H / 2;

    buttons = std::unique_ptr<ImageButtonRow>(new ImageButtonRow(x, y, w, h, BUTTON_SIZE, h - (w / 5 )));

}

void PostGameMenu::render(int score) {
    background->renderSprite(video, x, y, w, h);
    gameOver->render(video, (x + w / 2) - (gameOver->w / 2), y + GAME_OVER_OFFSET_Y / 2);
    finalScoreTitle->render(video,
            (x + w / 2) - (finalScoreTitle->w / 2),
            (y + h / 3) - (finalScoreTitle->h / 3));

    finalScore.render(video, std::to_string(score).c_str(), Colour::black, (x + w / 2) - (finalScore.w / 2), (y + h / 2) - (finalScore.h / 2));

    buttons->render();

}

void PostGameMenu::add(ImageButton *imageButton) {
    buttons->add(imageButton);
}

void PostGameMenu::handleEvent(SDL_Event &event) {
    buttons->handleEvent(event);
}


