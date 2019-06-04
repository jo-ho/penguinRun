#ifndef EMPTY_STATE_H
#define EMPTY_STATE_H


#include "state.h"

class EmptyState : public State {
public:
    StateType getStateType() override { return EMPTY; }

    void handleEvents() override {}

    void update(int elapsedTime) override {}

    void render() override {}

    void onEnter() override {}

    void onExit() override {}
};

#endif
