//
// Created by User on 2020-01-27.
//

#ifndef GAME1_ASSET_MANAGER_H
#define GAME1_ASSET_MANAGER_H





#include <map>
#include "sprite.h"


class AssetManager {
public:
    static const int SHIELD_SIZE = 128;

    static AssetManager * Get();
    static void Init(Video & video);
    Sprite * GetSprite(const char * name);

private:
    static const int STATE_BACKGROUND_W = 4866;
    static const int STATE_BACKGROUND_H = 3000;
    static const int FRAME_W = 2102;
    static const int FRAME_H = 2121;
    static const int HIGHSCORES_HL_W = 2080;
    static const int HIGHSCORES_HL_H = 408;
    static const int PAUSED_HL_W = 1388;
    static const int PAUSED_HL_H = 374;
    static const int SHIELD_ALPHA = 127;

    static AssetManager * instance;
    std::map<const char *, Sprite *> sprites;
    Video video;
    AssetManager(Video & video);
    ~AssetManager();
    void addSprite(const char * name, const char * fileName,
                   int w, int h, const SDL_Color * colorKey = nullptr);

};


#endif //GAME1_ASSET_MANAGER_H
