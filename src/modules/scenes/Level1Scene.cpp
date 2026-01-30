#include "Level1Scene.h"

Level1Scene::Level1Scene(Player* player) {
    cout<<"Creating Level 1 Scene"<<endl;
    this->player = player;
}

void Level1Scene::init() {

}

void Level1Scene::handleInput(InputManager& inputManager) {

}

void Level1Scene::update() {

}

void Level1Scene::render(Engine2D* engine2D) {
    engine2D->drawText("Game scene!", 100, 200, 32);
    //engine2D->drawSprite(player->getMySprite());
}