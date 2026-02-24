#include "Level1Scene.h"

Level1Scene::Level1Scene(Player* player) {
    this->player = player;
}

void Level1Scene::init(Engine2D* engine2D) {
    tilemap.loadFromFile("assets/maps/map-1.tmx"); // TODO: move to config

    const ObjectLayer* spawnLayer = tilemap.getSpawnLayer();
    for (const Object& spawn: spawnLayer->objects) {
        if (spawn.type == "soldier") {
            Soldier* soldier = new Soldier({spawn.position.x, spawn.position.y});
            soldier->init(engine2D);
            enemies.push_back(soldier);    
        }
    }
}

Vector2 Level1Scene::getCameraTarget() const {
    return player->getCurrentPosition();
}

void Level1Scene::handleInput(InputManager& inputManager) {
    player->handleInput(inputManager);
}

void Level1Scene::update(float dt) {
    player->update(dt);
    
    if (!tilemap.isCollision(player->getNextPosition())) {
        player->applyMovement();
    }

    for (Unit* unit: enemies) {
        unit->update(dt);
    }
}

void Level1Scene::render(Engine2D* engine2D, float alpha) {
    tilemap.render(engine2D, {0 , 1, 2});
    player->render(engine2D, alpha);
    for (Unit* unit: enemies) {
        unit->render(engine2D, alpha);
    }
    tilemap.render(engine2D, {3});
}