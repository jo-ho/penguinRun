#ifndef GAME_H
#define GAME_H

#include "sprite.h"
#include <vector>
#include <memory>


#include <SDL.h>
#include "video.h"
#include "button.h"
#include "animated_sprite.h"
#include "player.h"
#include "timer.h"
#include "score_pickup.h"
#include "pickup_manager.h"
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
