//
// Created by User on 2020-01-27.
//

#include "asset_manager.h"
#include "colour.h"

AssetManager * AssetManager::instance = nullptr;


AssetManager::AssetManager(Video & video) {
    this->video = video;
    SDL_Log("Start load");
    addSprite("default", "default.png", PICKUP_SIZE, PICKUP_SIZE);
    addSprite("main_menu_bg", "gui/background1-reduced.png", STATE_BACKGROUND_W, STATE_BACKGROUND_H);
    addSprite("high_scores_bg", "gui/background2-reduced.png", STATE_BACKGROUND_W, STATE_BACKGROUND_H);
    addSprite("play_bg", "under.png", PLAY_BG_W, PLAY_BG_H);
    addSprite("high_scores_frame", "gui/frames/hi-score-new.png", FRAME_W, FRAME_H);
    addSprite("high_scores_hl", "gui/headlines/hi-score.png", HIGHSCORES_HL_W, HIGHSCORES_HL_H);
    addSprite("paused_frame", "gui/frames/paused.png", FRAME_W, FRAME_H);
    addSprite("help_frame", "gui/frames/help-new.png", HELP_FRAME_W, HELP_FRAME_H);
    addSprite("credits_frame", "gui/frames/credits.png", HELP_FRAME_W, HELP_FRAME_H);
    addSprite("paused_hl", "gui/headlines/paused.png", PAUSED_HL_W, PAUSED_HL_H);
    addSprite("shield", "spr_shield.png", SHIELD_SIZE, SHIELD_SIZE);
    sprites["shield"]->setTextureAlphaMod(SHIELD_ALPHA);
    addSprite("play_unpressed", "gui/buttons/normal/play.png", MENU_BUTTON_SIZE, MENU_BUTTON_SIZE );
    addSprite("play_pressed", "gui/buttons/click/play.png", MENU_BUTTON_SIZE, MENU_BUTTON_SIZE);
    addSprite("records_unpressed", "gui/buttons/normal/records.png", MENU_BUTTON_SIZE,
              MENU_BUTTON_SIZE );
    addSprite("records_pressed", "gui/buttons/click/records.png", MENU_BUTTON_SIZE,
              MENU_BUTTON_SIZE );
    addSprite("help_unpressed", "gui/buttons/normal/help.png", MENU_BUTTON_SIZE, MENU_BUTTON_SIZE );
    addSprite("help_pressed", "gui/buttons/click/help.png", MENU_BUTTON_SIZE, MENU_BUTTON_SIZE );
    addSprite("home_unpressed", "gui/buttons/normal/home.png", MENU_BUTTON_SIZE, MENU_BUTTON_SIZE );
    addSprite("home_pressed", "gui/buttons/click/home.png", MENU_BUTTON_SIZE, MENU_BUTTON_SIZE );
    addSprite("back_unpressed", "gui/buttons/normal/left.png", SMALL_BUTTON_SIZE, SMALL_BUTTON_SIZE );
    addSprite("back_pressed", "gui/buttons/click/left.png", SMALL_BUTTON_SIZE, SMALL_BUTTON_SIZE );
    addSprite("paused_unpressed", "gui/buttons/normal/settings.png", SMALL_BUTTON_SIZE,
              SMALL_BUTTON_SIZE );
    addSprite("paused_pressed", "gui/buttons/click/settings.png", SMALL_BUTTON_SIZE,
              SMALL_BUTTON_SIZE );
    addSprite("credits_unpressed", "gui/buttons/normal/credits.png", SMALL_BUTTON_SIZE,
              SMALL_BUTTON_SIZE );
    addSprite("credits_pressed", "gui/buttons/click/credits.png", SMALL_BUTTON_SIZE,
              SMALL_BUTTON_SIZE );
    addSprite("score_pickup", "pickups/fish.png", PICKUP_SIZE, PICKUP_SIZE);
    addSprite("shield_pickup", "pickups/shield.png", PICKUP_SIZE, PICKUP_SIZE);
    addSprite("death_pickup", "pickups/death.png", PICKUP_SIZE, PICKUP_SIZE);
    addSprite("slow_pickup", "pickups/slow.png", PICKUP_SIZE, PICKUP_SIZE);
    addSprite("speed_pickup", "pickups/speed.png", PICKUP_SIZE, PICKUP_SIZE);
    addSprite("post_game_frame", "gui/frames/warning.png", FRAME_W, POST_GAME_FRAME_H);

    addFont("akashi36", DEFAULT_FONT_FILE, 36);
    addFont("akashi32", DEFAULT_FONT_FILE, 32);
    addFont("akashi48", DEFAULT_FONT_FILE, 48);
    addFont("akashi60", DEFAULT_FONT_FILE, 60);
    addFont("akashi96", DEFAULT_FONT_FILE, 96);
    SDL_Log("End load");
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
    for (auto itr = fonts.begin(); itr != fonts.end(); itr++) {
        TTF_CloseFont(itr->second);
    }
    delete instance;
}

void AssetManager::addSprite( const char * name, const char * fileName,
                                      int w, int h, const SDL_Color * colorKey) {
    sprites[name] =  new Sprite(video, fileName, w, h, colorKey);
}

Sprite *AssetManager::GetSprite(const char * name) {
    auto it = sprites.find(name);
    if (it == sprites.end()) return sprites["default"];
    return sprites[name];
}

void AssetManager::addFont(const char *name, const char *fileName, int size) {
    fonts[name] = TTF_OpenFont(fileName, size);
}

TTF_Font *AssetManager::GetFont(const char *name) {
    return fonts[name];
}


