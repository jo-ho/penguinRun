#include "timer.h"

#include <SDL.h>

Timer::Timer() : startTimeMs(SDL_GetTicks()), resetCount(0) {}

void Timer::reset() {
    startTimeMs = SDL_GetTicks();
    resetCount++;
}

unsigned int Timer::getTimeElapsedMs() {
    if (startTimeMs != 0) {
        return SDL_GetTicks() - startTimeMs;
    }
    return 0;
}

int Timer::getResetCount() {
    return resetCount;
}


