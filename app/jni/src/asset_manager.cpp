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


