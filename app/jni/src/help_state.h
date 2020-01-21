#ifndef GAME1_HELP_STATE_H
#define GAME1_HELP_STATE_H


#include "state.h"
#include "state_machine.h"
#include "video.h"

class HelpState : public State {
    HelpState(std::shared_ptr<StateMachine> stateMachine, Video & video);

    StateType getStateType() override;

    void handleEvents() override;

    void update(int elapsedTime) override;

    void render() override;

    void onEnter(void * param) override;

    void onExit() override;

};


#endif //GAME1_HELP_STATE_H
