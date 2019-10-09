#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H


#include <vector>
#include "state.h"
#include "state_machine.h"
#include "video.h"
#include "button.h"
#include "image_button.h"

class MainMenuState : public State {
public:
    MainMenuState(std::shared_ptr<StateMachine> stateMachine, Video & video);

    StateType getStateType() override;

    void handleEvents() override;

    void update(int elapsedTime) override;

    void render() override;

    void onEnter(void * param) override;

    void onExit() override;

private:
    std::shared_ptr<StateMachine> stateMachine;
    Video video;
    std::unique_ptr<ImageButton> playButton;


};

#endif
