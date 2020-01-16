
#ifndef TIMER_H
#define TIMER_H




class Timer {
public:
    Timer();
    void reset();
    void update(int elapsedTime);
    unsigned int getTimeElapsedMs();
    int getResetCount();
private:
    unsigned int startTimeMs;
    int resetCount;
};


#endif
