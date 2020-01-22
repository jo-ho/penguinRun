#ifndef GAME1_HELP_STATE_H
#define GAME1_HELP_STATE_H


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
    static const int BACKGROUND_WIDTH = 4866;

    static const int BACKGROUND_HEIGHT = 3000;
    static const int BACK_BUTTON_SPRITE_SIZE = 701;
    static const int BACK_BUTTON_SIZE = BACK_BUTTON_SPRITE_SIZE / 7;

    Video video;
    std::shared_ptr<StateMachine> stateMachine;
    std::unique_ptr<Sprite> background;
    std::unique_ptr<ImageButton> backButton;


};


#endif //GAME1_HELP_STATE_H
