
#ifndef TIMER_H
#define TIMER_H




class Timer {
public:
    Timer();
    void reset();
    unsigned int getTimeElapsedMs();
    int getResetCount();
private:
    unsigned int startTimeMs;
    int resetCount;
};


#endif
