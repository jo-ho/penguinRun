#ifndef PLAY_STATE_H
#define PLAY_STATE_H


#include "state.h"
#include "state_machine.h"
#include "video.h"
#include "pickup_manager.h"
#include "text.h"
#include "background.h"
#include "death_animation.h"

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
    Text text = Text(32);
    std::vector<long long> fingerIDs;

    bool deathAnimationComplete; //TODO remove?
    std::unique_ptr<DeathAnimation> deathAnimation;
};


#endif
