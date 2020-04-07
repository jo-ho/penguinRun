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
    static const int FRAME_W = 2102;
    static const int POST_GAME_FRAME_H = 1561;

    static AssetManager * Get();
    static void Init(Video & video);
    Sprite * GetSprite(const char * name);
    TTF_Font * GetFont(const char * name);

private:
    static const int STATE_BACKGROUND_W = 4866;
    static const int STATE_BACKGROUND_H = 3000;

    static const int FRAME_H = 2121;
    static const int HIGHSCORES_HL_W = 2080;
    static const int HIGHSCORES_HL_H = 408;
    static const int PAUSED_HL_W = 1388;
    static const int PAUSED_HL_H = 374;
    static const int SHIELD_ALPHA = 127;
    static const int MENU_BUTTON_SIZE = 300;
    static const int BACK_BUTTON_SIZE = 701;
    static const int PAUSE_BUTTON_SIZE = 100;
    static const int HELP_FRAME_W = 1920;
    static const int HELP_FRAME_H = 1080;
    static const int PLAY_BG_W = 1024;
    static const int PLAY_BG_H = 768;
    static const int PICKUP_SIZE = 64;



    const char * DEFAULT_FONT_FILE = "akashi.ttf";

    static AssetManager * instance;
    std::map<const char *, Sprite *> sprites;
    std::map<const char *, TTF_Font *> fonts;
    Video video;
    AssetManager(Video & video);
    ~AssetManager();
    void addSprite(const char * name, const char * fileName,
                   int w, int h, const SDL_Color * colorKey = nullptr);
    void addFont(const char * name, const char * fileName, int size);

};


#endif //GAME1_ASSET_MANAGER_H
