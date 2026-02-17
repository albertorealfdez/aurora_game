#ifndef LEVEL1_SCENE_H
#define LEVEL1_SCENE_H

#include "Scene.h"
#include "Player.h"
#include "TileMap.h"

class Level1Scene: public Scene{
    private:
        Player* player;
        TileMap tilemap;
        
    public:
        Level1Scene(Player* player);
        
        void init() override;
        Vector2 getCameraTarget() const override;
        
        void handleInput(InputManager& inputManager) override;
        void update(float dt) override;
        void render(Engine2D* engine2D, float alpha) override;
};

#endif /* LEVEL1_SCENE_H */