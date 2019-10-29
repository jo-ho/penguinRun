#ifndef PLAY_STATE_H
#define PLAY_STATE_H


static const int BACKGROUND_WIDTH = 1024;
static const int BACKGROUND_HEIGHT = 768;
static const char *const BACKGROUND_FILENAME = "under.png";

static const int FLOOR_HEIGHT_FACTOR = 8;

static const int PAUSE_BUTTON_SIZE = 100;

#include "state.h"
#include "state_machine.h"
#include "video.h"
#include "pickup_manager.h"
#include "text.h"
#include "background.h"
#include "death_animation.h"
#include "button.h"
#include "image_button.h"

class PlayState : public State {
public:
    PlayState(std::shared_ptr<StateMachine> stateMachine, Video & video);

    StateType getStateType() override;

    void handleEvents() override;

    void update(int elapsedTime) override;

    void render() override;

    void onEnter(void * param) override;

    void onExit() override;

private:
    std::shared_ptr<StateMachine> stateMachine;
    Video video;
    std::unique_ptr<Player> player;
    std::unique_ptr<ScrollableBackground> background;
    std::unique_ptr<PickupManager>  pickupManager;
    Text score = Text(32);
    std::vector<long long> fingerIDs;

    bool deathAnimationComplete; //TODO remove?
    std::unique_ptr<DeathAnimation> deathAnimation;
    int moveAreaHeight;
    std::unique_ptr<ImageButton> pauseButton;
};


#endif
