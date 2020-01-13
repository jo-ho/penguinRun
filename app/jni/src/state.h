#ifndef STATE_H
#define STATE_H


class State {
public:
    enum StateType{MAIN_MENU, PLAY, QUIT, EMPTY, HIGH_SCORES};
    virtual StateType getStateType() = 0;
    virtual void handleEvents() = 0;
    virtual void update(int elapsedTime) = 0;
    virtual void render() = 0;
    virtual void onEnter(void * param) = 0;
    virtual void onExit() = 0;
};


#endif
