#include "Level1Scene.h"
#include <iostream>
Level1Scene::Level1Scene(Player* player) {
    this->player = player;
}

void Level1Scene::init() {

}

void Level1Scene::handleInput(InputManager& inputManager) {
    if (inputManager.isKeyDown(Key::D)) {
        player->setState(PlayerState::WalkRight);
    }
}

void Level1Scene::update() {
    player->update();
}

void Level1Scene::render(Engine2D* engine2D) {
    engine2D->drawSprite(player->getMySprite());
}