#include "IntroState.h"
#include "PlayState.h"
#include "Game.h"

IntroState::IntroState(Game* game): State(game) {}

void IntroState::init(Engine2D* engine2D) {
    cameraStartPosition = {1280/2.f, 720/2.f};
    introText.setFont(engine2D->getFont("title"));
    introText.setText("UNFINISHED LANDS");
    introText.setSize(25);
    introText.setPosition(0,0);

    cout<<"Initialized IntroState"<<endl;
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
    engine2D->drawText(introText);
}