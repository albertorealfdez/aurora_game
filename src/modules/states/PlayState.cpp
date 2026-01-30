#include "PlayState.h"
#include "Game.h"
#include "Level1Scene.h"

PlayState::PlayState(Game* game): State(game) {
}

void PlayState::init() {
    cout<<"Initializing PlayState"<<endl;
    player = new Player();
    player->init();

    sceneManager = new SceneManager();
    sceneManager->changeScene(new Level1Scene(player));
    sceneManager->processPending();
}

void PlayState::handleInput(InputManager& inputManager) {
    sceneManager->getCurrentScene()->handleInput(inputManager);
}

void PlayState::update() {
    sceneManager->getCurrentScene()->update();
}

void PlayState::render(Engine2D* engine2D) {
    sceneManager->getCurrentScene()->render(engine2D);
}