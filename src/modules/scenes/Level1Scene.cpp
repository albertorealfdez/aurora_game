#include "Level1Scene.h"

Level1Scene::Level1Scene(Player* player) {
    this->player = player;

    enemies.push_back(new Soldier({1280/2.f + 100.f, 720/2.f}));
}

void Level1Scene::init(Engine2D* engine2D) {
    tilemap.loadFromFile("assets/maps/map-1.tmx"); // TODO: move to config

    for (Unit* unit: enemies) {
        unit->init(engine2D);
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