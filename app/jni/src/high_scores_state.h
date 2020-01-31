//
// Created by User on 2020-01-09.
//

#ifndef GAME1_HIGH_SCORES_STATE_H
#define GAME1_HIGH_SCORES_STATE_H



#include <SDL_events.h>
#include <vector>
#include "state.h"
#include "text.h"
#include "state_machine.h"
#include "sprite.h"
#include "high_scores_frame.h"
#include "image_button.h"

class HighScoresState : public State {

public:
    HighScoresState(std::shared_ptr<StateMachine> stateMachine, Video & video);


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

    std::shared_ptr<StateMachine> stateMachine;
    std::unique_ptr<HighScoresFrame> frame;
    Sprite * background;
    std::unique_ptr<ImageButton> backButton;
    Video video;

};


#endif //GAME1_HIGH_SCORES_STATE_H
