#ifndef PLAY_STATE_H
#define PLAY_STATE_H

#include "State.h"
#include "SceneManager.h"
#include "Player.h"

class PlayState: public State {
    private:
        SceneManager* sceneManager;
        Player* player;

    public:
        PlayState(Game* game);
        ~PlayState() override = default;

        void init();
        void handleInput(InputManager& inputManager) override;
        void update(float dt) override;
        void render(Engine2D* engine2D, float alpha) override;
};

#endif /* PLAY_STATE_H */