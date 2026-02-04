#include "Level1Scene.h"

Level1Scene::Level1Scene(Player* player) {
    this->player = player;
}

void Level1Scene::init() {

}

void Level1Scene::handleInput(InputManager& inputManager) {
    player->handleInput(inputManager);
}

void Level1Scene::update(float dt) {
    player->update(dt);
}

void Level1Scene::render(Engine2D* engine2D) {
    engine2D->drawSprite(player->getMySprite());
}