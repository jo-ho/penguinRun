//
// Created by User on 2020-01-27.
//

#include "asset_manager.h"
#include "colour.h"

AssetManager * AssetManager::instance = nullptr;


AssetManager::AssetManager(Video & video) {
    this->video = video;
    addSprite("main_menu_bg", "gui/background1.png", STATE_BACKGROUND_W, STATE_BACKGROUND_H);
    addSprite("high_scores_bg", "gui/background2.png", STATE_BACKGROUND_W, STATE_BACKGROUND_H);
    addSprite("high_scores_frame", "gui/frames/hi-score-new.png", FRAME_W, FRAME_H, &Colour::black);
    addSprite("high_scores_hl", "gui/headlines/hi-score.png", HIGHSCORES_HL_W, HIGHSCORES_HL_H);
    addSprite("paused_frame", "gui/frames/paused.png", FRAME_W, FRAME_H);
    addSprite("paused_hl", "gui/headlines/paused.png", PAUSED_HL_W, PAUSED_HL_H);
    addSprite("shield", "spr_shield.png", SHIELD_SIZE, SHIELD_SIZE, &Colour::white);
    sprites["shield"]->setTextureAlphaMod(SHIELD_ALPHA);
    addSprite("play_unpressed", "gui/buttons/normal/play.png", MENU_BUTTON_SIZE, MENU_BUTTON_SIZE, &Colour::black );
    addSprite("play_pressed", "gui/buttons/click/play.png", MENU_BUTTON_SIZE, MENU_BUTTON_SIZE, &Colour::black );
    addSprite("records_unpressed", "gui/buttons/normal/records.png", MENU_BUTTON_SIZE,
              MENU_BUTTON_SIZE, &Colour::black );
    addSprite("records_pressed", "gui/buttons/click/records.png", MENU_BUTTON_SIZE,
              MENU_BUTTON_SIZE, &Colour::black );
    addSprite("help_unpressed", "gui/buttons/normal/help.png", MENU_BUTTON_SIZE, MENU_BUTTON_SIZE, &Colour::black );
    addSprite("help_pressed", "gui/buttons/click/help.png", MENU_BUTTON_SIZE, MENU_BUTTON_SIZE, &Colour::black );
    addSprite("home_unpressed", "gui/buttons/normal/home.png", MENU_BUTTON_SIZE, MENU_BUTTON_SIZE, &Colour::black );
    addSprite("home_pressed", "gui/buttons/click/home.png", MENU_BUTTON_SIZE, MENU_BUTTON_SIZE, &Colour::black );
    addSprite("back_unpressed", "gui/buttons/normal/left.png", BACK_BUTTON_SIZE, BACK_BUTTON_SIZE, &Colour::black );
    addSprite("back_pressed", "gui/buttons/click/left.png", BACK_BUTTON_SIZE, BACK_BUTTON_SIZE, &Colour::black );
    addSprite("paused_unpressed", "gui/buttons/normal/settings.png", PAUSE_BUTTON_SIZE,
              PAUSE_BUTTON_SIZE, &Colour::black );
    addSprite("paused_pressed", "gui/buttons/click/settings.png", PAUSE_BUTTON_SIZE,
              PAUSE_BUTTON_SIZE, &Colour::black );
}

void AssetManager::Init(Video &video) {
    instance = new AssetManager(video);
}

AssetManager *AssetManager::Get() {
    return instance;
}

AssetManager::~AssetManager() {
    for(auto itr = sprites.begin(); itr != sprites.end(); itr++)
    {
        delete itr->second;
    }
    delete instance;
}

void AssetManager::addSprite( const char * name, const char * fileName,
                                      int w, int h, const SDL_Color * colorKey) {
    sprites[name] =  new Sprite(video, fileName, w, h, colorKey);
}

Sprite *AssetManager::GetSprite(const char * name) {
    return sprites[name];
}


