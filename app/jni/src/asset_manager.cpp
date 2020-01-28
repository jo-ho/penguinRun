//
// Created by User on 2020-01-27.
//

#include "asset_manager.h"

AssetManager * AssetManager::instance = nullptr;


AssetManager::AssetManager() {}

AssetManager *AssetManager::Get() {
    if (!instance) {
        instance = new AssetManager();
    }
    return instance;
}

AssetManager::~AssetManager() {
    delete instance;
}


