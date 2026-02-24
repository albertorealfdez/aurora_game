#ifndef LEVEL1_SCENE_H
#define LEVEL1_SCENE_H

#include <vector>
#include "Scene.h"
#include "Soldier.h"
#include "TileMap.h"
#include "ObjectLayer.h"

class Level1Scene: public Scene{
    private:
        Player* player;
        vector<Unit*> enemies;
        TileMap tilemap;
        
    public:
        Level1Scene();
        
        void init(Engine2D* engine2D) override;
        void setPlayer(Player* player) override;
        Vector2 getCameraTarget() const override;
        Vector2 getPlayerSpawn() const override;

        void handleInput(InputManager& inputManager) override;
        void update(float dt) override;
        void render(Engine2D* engine2D, float alpha) override;
};

#endif /* LEVEL1_SCENE_H */