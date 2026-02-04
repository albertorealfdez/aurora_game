#include "Clock.h"
#include <iostream>

Clock::Clock() {
    restart();
}

void Clock::restart() {
    lastTime = chrono::high_resolution_clock::now();
}

float Clock::getElapsedTime() {
    chrono::high_resolution_clock::time_point currentTime = chrono::high_resolution_clock::now();
    chrono::duration<float> diff = currentTime - lastTime;
    return diff.count();
}