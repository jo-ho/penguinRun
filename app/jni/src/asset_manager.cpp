//
// Created by User on 2020-01-27.
//

#include "asset_manager.h"

AssetManager * AssetManager::instance = nullptr;


AssetManager::AssetManager(Video & video) {}

void AssetManager::Init(Video &video) {
    instance = new AssetManager(video);
}

AssetManager *AssetManager::Get() {
    return instance;
}

AssetManager::~AssetManager() {
    delete instance;
}

void AssetManager::addSprite(Video & video, const std::string& name, const std::string& fileName,
                                      int w, int h, const SDL_Color * colorKey) {
    auto * sprite = new Sprite(video, fileName.c_str(), w, h, colorKey);
    sprites[name] = sprite;
}


