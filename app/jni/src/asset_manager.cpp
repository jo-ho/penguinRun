//
// Created by User on 2020-01-27.
//

#include "asset_manager.h"

AssetManager * AssetManager::instance = nullptr;


AssetManager::AssetManager(Video & video) {
    this->video = video;
    addSprite("main_menu_bg", "gui/background1.png", 4866, 3000);
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


