#include "IntroState.h"
#include "PlayState.h"
#include "Game.h"

IntroState::IntroState(Game* game): State(game) {}

void IntroState::init() {
    cout<<"Initializing IntroState"<<endl;
}

void IntroState::handleInput(InputManager& inputManager) {
    if (inputManager.isKeyPressed(Key::Space)) {
        game->getStateManager()->changeState(new PlayState(game));
    }
}

void IntroState::update(float dt) {
    
}

void IntroState::render(Engine2D* engine2D, float alpha) {
    engine2D->drawText("Hello", 100, 200, 32);
}