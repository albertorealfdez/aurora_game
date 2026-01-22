#ifndef INTRO_STATE_H
#define INTRO_STATE_H

#include "State.h"

class IntroState: public State {
    public:
        IntroState(Game* game);
        ~IntroState() override = default;

        void init();
        void handleInput(InputManager& input) override;
        void update() override;
        void render(Engine2D* engine2D) override;
};

#endif /* INTRO_STATE_H */