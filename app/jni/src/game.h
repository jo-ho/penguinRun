#ifndef GAME_H
#define GAME_H

#include "Sprite.h"
#include <vector>
#include <memory>


#include <SDL.h>
#include "Video.h"
#include "Button.h"
#include "AnimatedSprite.h"
#include "Player.h"
#include "Timer.h"
#include "ScorePickup.h"
#include "PickupManager.h"
#include "text.h"

const static int GAME_FPS = 60;
const static int NUM_BUTTONS_MENU = 3;

class Game {
    public:
        Game();
        ~Game();
    private:
        std::vector<std::shared_ptr<Button>>  buttons;
        std::shared_ptr<Player> player;

        Video video;
        PickupManager * pickupManager;
        Text text;

        enum buttonID { MENU_BUTTON_START, MENU_BUTTON_OPTIONS, MENU_BUTTON_QUIT };

        void initSprites();
        void menuLoop();
        void renderMenu();


        void startGame();
        void gameLoop();
        void renderGame();
        void updateGame(int elapsedTime);

        void checkCollisions();
};


#endif
