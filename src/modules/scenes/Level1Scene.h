#ifndef LEVEL1_SCENE_H
#define LEVEL1_SCENE_H

#include "Scene.h"
#include "Player.h"

class Level1Scene: public Scene{
    private:
        Player* player;
    public:
        Level1Scene(Player* player);
        
        void init() override;
        void handleInput(InputManager& input) override;
        void update() override;
        void render(Engine2D* engine2D) override;
};

#endif /* LEVEL1_SCENE_H */