#ifndef GAME1_HELP_STATE_H
#define GAME1_HELP_STATE_H


static const int PICKUP_SIZE = 64;

static const int DESC_TEXT_SIZE = 32;

static const int PENGUIN_WIDTH = 52;

static const int PENGUIN_HEIGHT = 30;

#include "state.h"
#include "state_machine.h"
#include "video.h"
#include "image_button.h"
#include "high_scores_frame.h"

class HelpState : public State {
public:
    HelpState(std::shared_ptr<StateMachine> stateMachine, Video & video);

    StateType getStateType() override;

    void handleEvents() override;

    void update(int elapsedTime) override;

    void render() override;

    void onEnter(void * param) override;

    void onExit() override;

private:
    static const int BACK_BUTTON_SPRITE_SIZE = 701;
    static const int BACK_BUTTON_SIZE = BACK_BUTTON_SPRITE_SIZE / 7;

    Video video;
    std::shared_ptr<StateMachine> stateMachine;
    Sprite * background;
    std::unique_ptr<ImageButton> backButton;
    Text desc = Text(DESC_TEXT_SIZE);
    Text title = Text(48);


};


#endif //GAME1_HELP_STATE_H
