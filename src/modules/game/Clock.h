#include <chrono>

using namespace std;

class Clock {
    private:
        chrono::high_resolution_clock::time_point lastTime;

    public:
        Clock();
        void restart();
        float getElapsedTime();
};