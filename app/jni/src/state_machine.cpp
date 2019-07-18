#include "state_machine.h"
#include "empty_state.h"

StateMachine::StateMachine() {
    running = true;
    currentState = std::make_shared<EmptyState>();
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

void StateMachine::change(State::StateType stateType, void * param) {
    currentState->onExit();
    currentState = states[stateType];
    currentState->onEnter(param);
}

void StateMachine::add(std::shared_ptr<State> state) {
    states[state->getStateType()] = state;
}

bool StateMachine::isRunning() {
    return running;
}

void StateMachine::stopRunning() {
    running = false;
}
