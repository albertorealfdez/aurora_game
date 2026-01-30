#ifndef LEVEL1_SCENE_H
#define LEVEL1_SCENE_H

#include "Scene.h"

class Level1Scene: public Scene{
    public:
        Level1Scene();
        
        void init() override;
        void handleInput(InputManager& input) override;
        void update() override;
        void render(Engine2D* engine2D) override;
};

#endif /* LEVEL1_SCENE_H */