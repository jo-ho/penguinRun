#ifndef PLAY_STATE_H
#define PLAY_STATE_H


#include "state.h"
#include "state_machine.h"
#include "video.h"
#include "pickup_manager.h"
#include "text.h"

class PlayState : public State {
public:
    PlayState(std::shared_ptr<StateMachine> stateMachine, Video & video);

    StateType getStateType() override;

    void handleEvents() override;

    void update(int elapsedTime) override;

    void render() override;

    void onEnter() override;

    void onExit() override;

private:
    std::shared_ptr<StateMachine> stateMachine;
    Video video;
    std::shared_ptr<Player> player;
    std::shared_ptr<PickupManager>  pickupManager;
    Text text = Text(32);
    std::vector<long long> fingerIDs;
};


#endif
