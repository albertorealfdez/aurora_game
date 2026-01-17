#ifndef INTRO_STATE_H
#define INTRO_STATE_H

#include "State.h"

class IntroState: public State {
    public:
        IntroState(Game* game);
        ~IntroState() override = default;

        void init();
        void handleEvents();
        void update();
        void render(Engine2D* engine2D);
};

#endif /* INTRO_STATE_H */