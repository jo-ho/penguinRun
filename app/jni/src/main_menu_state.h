#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H


static const int BUTTON_SIZE = 300;



#include <vector>
#include "state.h"
#include "state_machine.h"
#include "video.h"

#include "image_button.h"
#include "image_button_row.h"
#include "text.h"
#include "static_text.h"
#include "colour.h"

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
    std::unique_ptr<StaticText> title;
    Sprite * background;
    std::unique_ptr<ImageButtonRow> row;


};

#endif
