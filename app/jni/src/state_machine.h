#ifndef GAME1_STATE_MACHINE_H
#define GAME1_STATE_MACHINE_H

#include <map>
#include "state.h"

class StateMachine {
public:

    StateMachine();

    void handleEvents();
    void update(int elapsedTime);
    void render();

    void change(State::StateType stateType, void * param);
    void add(std::shared_ptr<State> startState);

    bool isRunning();
    void stopRunning();

private:
    std::map<State::StateType, std::shared_ptr<State>> states;
    std::shared_ptr<State> currentState;
    bool running;

};


#endif
