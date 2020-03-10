#ifndef PLAY_STATE_H
#define PLAY_STATE_H





static const int FLOOR_HEIGHT_FACTOR = 8;

static const int PAUSE_BUTTON_SIZE = 100;
static const int BUTTON_SPRITE_SIZE = 300;


#include "state.h"
#include "state_machine.h"
#include "video.h"
#include "pickup_manager.h"
#include "text.h"
#include "background.h"
#include "death_animation.h"

#include "image_button.h"
#include "pause_menu.h"
#include "post_game_menu.h"

class PlayState : public State {
public:
    PlayState(std::shared_ptr<StateMachine> stateMachine, Video & video);

    StateType getStateType() override;

    void handleEvents() override;

    void update(int elapsedTime) override;

    void render() override;

    void onEnter(void * param) override;

    void onExit() override;

    void pause();

    void handleInput(SDL_Event & event);

private:

    std::shared_ptr<StateMachine> stateMachine;
    Video video;
    std::unique_ptr<Player> player;
    std::unique_ptr<ScrollableBackground> background;
    std::unique_ptr<PickupManager>  pickupManager;
    std::unique_ptr<PauseMenu>  pauseMenu;
    Text score = Text(48);
    std::vector<long long> fingerIDs;

    std::unique_ptr<DeathAnimation> deathAnimation;
    std::unique_ptr<PostGameMenu> postGameMenu;
    int moveAreaHeight;
    std::unique_ptr<ImageButton> pauseButton;
    bool paused;

};


#endif
