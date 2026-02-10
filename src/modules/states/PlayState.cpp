#include "PlayState.h"
#include "Game.h"
#include "Level1Scene.h"

PlayState::PlayState(Game* game): State(game) {
    player = new Player();
    sceneManager = new SceneManager();
}

void PlayState::init(Engine2D* engine2D) {
    player->init(engine2D);
    engine2D->loadTexture("player_walk", "assets/sprites/player_walk.png");
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