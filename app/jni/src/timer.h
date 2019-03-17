
#ifndef TIMER_H
#define TIMER_H




class Timer {
public:
    Timer();
    void reset();
    unsigned int getTimeElapsedMs();
private:
    unsigned int startTimeMs;
};


#endif
