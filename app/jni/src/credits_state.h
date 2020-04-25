//
// Created by Admin on 2020-04-24.
//

#ifndef GAME1_CREDITS_STATE_H
#define GAME1_CREDITS_STATE_H


#include "state.h"
#include "video.h"
#include "state_machine.h"
#include "sprite.h"
#include "image_button.h"

class CreditsState : public State {
public:
    CreditsState(std::shared_ptr<StateMachine> stateMachine, Video & video);

    StateType getStateType() override;

    void handleEvents() override;

    void update(int elapsedTime) override;
    void render() override;

    void onEnter(void * param) override;

    void onExit() override;

private:
    Video video;
    std::shared_ptr<StateMachine> stateMachine;
    std::unique_ptr<ImageButton> backButton;
    Sprite * background;



};


#endif //GAME1_CREDITS_STATE_H
