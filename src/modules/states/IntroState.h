#ifndef INTRO_STATE_H
#define INTRO_STATE_H

#include "State.h"

class IntroState: public State {
    public:
        IntroState(Game* game);
        ~IntroState() override = default;

        void init();
        void handleInput(InputManager& inputManager) override;
        void update(float dt) override;
        void render(Engine2D* engine2D) override;
};

#endif /* INTRO_STATE_H */