//
// Created by User on 2020-01-27.
//

#ifndef GAME1_ASSET_MANAGER_H
#define GAME1_ASSET_MANAGER_H

#include <map>
#include "sprite.h"


class AssetManager {
public:

    static AssetManager * Get();
    static void Init(Video & video);

private:
    static AssetManager * instance;
    std::map<std::string, Sprite *> sprites;
    AssetManager(Video & video);
    ~AssetManager();
    void addSprite(Video & video, const std::string& name, const std::string& fileName,
                   int w, int h, const SDL_Color * colorKey = nullptr);
};


#endif //GAME1_ASSET_MANAGER_H
