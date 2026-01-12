#ifndef INTRO_STATE_H
#define INTRO_STATE_H

#include "State.h"

class IntroState: public State {
    public:
        IntroState();

        void init();
        void handleEvents();
        void update();
        void render();
};

#endif /* INTRO_STATE_H */