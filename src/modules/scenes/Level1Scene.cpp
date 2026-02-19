#include "Level1Scene.h"

Level1Scene::Level1Scene(Player* player) {
    this->player = player;
}

void Level1Scene::init() {
    tilemap.loadFromFile("assets/maps/map-1.tmx"); // TODO: move to config
}

Vector2 Level1Scene::getCameraTarget() const {
    return player->getCurrentPosition();
}

void Level1Scene::handleInput(InputManager& inputManager) {
    player->handleInput(inputManager);
}

void Level1Scene::update(float dt) {
    player->update(dt);

    //if (player->getCurrentPosition() != player->getNextPosition()) {
    if (!tilemap.isCollision(player->getNextPosition())) {
        player->applyMovement();
    }
    //}
}

void Level1Scene::render(Engine2D* engine2D, float alpha) {
    tilemap.render(engine2D, {0 , 1});
    player->render(engine2D, alpha);
    tilemap.render(engine2D, {2});
}