#include "IntroState.h"
#include "PlayState.h"
#include "Game.h"

IntroState::IntroState(Game* game): State(game) {}

void IntroState::init() {
    cout<<"Initializing IntroState"<<endl;
    cameraStartPosition = {640/2.f, 360/2.f};
}

Vector2 IntroState::getCameraTarget() const {
    return cameraStartPosition;
}

void IntroState::handleInput(InputManager& inputManager) {
    if (inputManager.isKeyPressed(Key::Space)) {
        game->getStateManager()->changeState(new PlayState(game));
    }
}

void IntroState::update(float dt) {
    
}

void IntroState::render(Engine2D* engine2D, float alpha) {
    engine2D->drawText("UNFINISHED LANDS", 640/3.f - 20, 360/2.f, 25); // TODO: move to config?
}