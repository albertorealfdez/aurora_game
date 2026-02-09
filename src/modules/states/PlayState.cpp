#include "PlayState.h"
#include "Game.h"
#include "Level1Scene.h"

PlayState::PlayState(Game* game): State(game) {
    player = new Player(game->getTextureManager());
    sceneManager = new SceneManager();
}

void PlayState::init() {
    player->init();
    
    sceneManager->changeScene(new Level1Scene(player));
    sceneManager->processPending();
}

Vector2 PlayState::getCameraTarget() const {
    return sceneManager->getCurrentScene()->getCameraTarget();
}

void PlayState::handleInput(InputManager& inputManager) {
    sceneManager->getCurrentScene()->handleInput(inputManager);
}

void PlayState::update(float dt) {
    sceneManager->getCurrentScene()->update(dt);
}

void PlayState::render(Engine2D* engine2D, float alpha) {
    sceneManager->getCurrentScene()->render(engine2D, alpha);
}