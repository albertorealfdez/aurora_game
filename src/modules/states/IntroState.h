#ifndef INTRO_STATE_H
#define INTRO_STATE_H

#include "State.h"

class IntroState: public State {
    private:
        Vector2 cameraStartPosition;

    public:
        IntroState(Game* game);
        ~IntroState() override = default;

        void init();
        Vector2 getCameraTarget() const override;
        
        void handleInput(InputManager& inputManager) override;
        void update(float dt) override;
        void render(Engine2D* engine2D, float alpha) override;
};

#endif /* INTRO_STATE_H */