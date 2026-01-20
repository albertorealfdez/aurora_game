#include "IntroState.h"
#include "Game.h"

IntroState::IntroState(Game* game): State(game) {}

void IntroState::init() {
    cout<<"Initializing IntroState"<<endl;
}

void IntroState::handleInput(InputManager& input) {
    if (input.isKeyPressed(Key::Space)) {
        game->getStateManager()->changeState(NULL);
    }
}

void IntroState::update() {
    
}

void IntroState::render(Engine2D* engine2D) {
    engine2D->drawText("Hello", 100, 200, 32);
}