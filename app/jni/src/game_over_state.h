#ifndef GAME_OVER_STATE_H
#define GAME_OVER_STATE_H


#include "state.h"
#include "death_animation.h"
#include "state_machine.h"
#include "player.h"
#include "background.h"
#include <SDL.h>

class GameOverState : public State {
public:
    GameOverState(std::shared_ptr<StateMachine> stateMachine, Video &video);

    StateType getStateType() override;

    void handleEvents() override;

    void update(int elapsedTime) override;

    void render() override;

    void onEnter(void *param) override;

    void onExit() override;

private:
    bool deathAnimationComplete; //TODO remove?
    std::unique_ptr<Player> player;
    std::shared_ptr<StateMachine> stateMachine;
    Video video;
    std::unique_ptr<Background> background;
    std::unique_ptr<DeathAnimation> deathAnimation;
};


#endif
