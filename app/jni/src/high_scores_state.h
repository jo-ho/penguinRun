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
    std::shared_ptr<StateMachine> stateMachine;
    std::unique_ptr<HighScoresFrame> frame;
    Video video;

};


#endif //GAME1_HIGH_SCORES_STATE_H
