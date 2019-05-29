#ifndef GAME1_STATE_MACHINE_H
#define GAME1_STATE_MACHINE_H

#include <map>
#include "state.h"

class StateMachine {
public:

    StateMachine(std::shared_ptr<State> startState);

    void handleEvents();
    void update(int elapsedTime);
    void render();

    void change(State::StateType stateType);
    void add(std::shared_ptr<State> startState);

private:
    std::map<State::StateType, std::shared_ptr<State>> states;
    std::shared_ptr<State> currentState;

};


#endif
