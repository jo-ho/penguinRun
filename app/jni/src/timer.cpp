#include "timer.h"

#include <SDL.h>

Timer::Timer() : startTimeMs(0) {}

void Timer::reset() {
    startTimeMs = SDL_GetTicks();
}

unsigned int Timer::getTimeElapsedMs() {
    if (startTimeMs != 0) {
        return SDL_GetTicks() - startTimeMs;
    }
    return 0;
}



