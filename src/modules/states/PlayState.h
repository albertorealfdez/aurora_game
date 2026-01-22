#ifndef PLAY_STATE_H
#define PLAY_STATE_H

#include "State.h"

class PlayState: public State {
    public:
        PlayState(Game* game);
        ~PlayState() override = default;

        void init();
        void handleInput(InputManager& input) override;
        void update() override;
        void render(Engine2D* engine2D) override;
};

#endif /* PLAY_STATE_H */