#include "state_machine.h"

StateMachine::StateMachine(std::shared_ptr<State> startState) {
    this->currentState = startState;
}

void StateMachine::handleEvents() {
    currentState->handleEvents();
}

void StateMachine::update(int elapsedTime) {
    currentState->update(elapsedTime);
}

void StateMachine::render() {
    currentState->render();
}

void StateMachine::change(State::StateType stateType) {
    currentState->onExit();
    currentState = states[stateType];
    currentState->onEnter();
}

void StateMachine::add(std::shared_ptr<State> state) {
    states[state->getStateType()] = state;
}
