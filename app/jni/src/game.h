#ifndef GAME_H
#define GAME_H


#include "video.h"
#include "state_machine.h"

class Game {
public:
    Game();
    ~Game();

private:
    Video video;
    std::shared_ptr<StateMachine> stateMachine;

    void mainLoop();
    void addStates();

};


#endif
