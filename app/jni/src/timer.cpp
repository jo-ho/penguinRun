#include "timer.h"

#include <SDL.h>

Timer::Timer() : startTimeMs(SDL_GetTicks()), resetCount(0) {}

void Timer::reset() {
    startTimeMs = 0;
    resetCount++;
}

unsigned int Timer::getTimeElapsedMs() {
    if (startTimeMs != 0) {
        return startTimeMs;
    }
    return 0;
}

int Timer::getResetCount() {
    return resetCount;
}

void Timer::update(int elapsedTime) {
    startTimeMs += elapsedTime;

}


