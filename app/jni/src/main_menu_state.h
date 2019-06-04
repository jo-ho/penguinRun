#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H


#include <vector>
#include "state.h"
#include "state_machine.h"
#include "video.h"
#include "button.h"

class MainMenuState : public State {
public:
    MainMenuState(std::shared_ptr<StateMachine> stateMachine, Video & video);

    StateType getStateType() override;

    void handleEvents() override;

    void update(int elapsedTime) override;

    void render() override;

    void onEnter() override;

    void onExit() override;

private:
    std::shared_ptr<StateMachine> stateMachine;
    Video video;
    std::vector<std::shared_ptr<Button>>  buttons;
    enum buttonID { MENU_BUTTON_START, MENU_BUTTON_OPTIONS, MENU_BUTTON_QUIT };


};

#endif
