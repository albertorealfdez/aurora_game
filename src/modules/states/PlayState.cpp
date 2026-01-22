#include "PlayState.h"
#include "Game.h"

PlayState::PlayState(Game* game): State(game) {}

void PlayState::init() {
    cout<<"Initializing PlayState"<<endl;
}

void PlayState::handleInput(InputManager& input) {
    /*if (input.isKeyPressed(Key::Space)) {
        // game->getStateManager()->changeState(NULL);
    }*/
}

void PlayState::update() {
    
}

void PlayState::render(Engine2D* engine2D) {
    engine2D->drawText("Game!", 100, 200, 32);
}