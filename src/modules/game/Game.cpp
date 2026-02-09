#include "Game.h"
#include "IntroState.h"

Game* Game::instance = 0;

Game::Game() {
    engine2D = new Engine2D();
    stateManager = new StateManager();
    stateManager->pushState(new IntroState(this));
    stateManager->processPending();

    running = true;
    limitRender = true;
    renderFPS = 60;
    updateTime = 1.f/15.f;
    smoothFactor = 0.1f;
    
    loadTextures();
}

Game::~Game() {
    delete engine2D;
    delete stateManager;
}

void Game::loadTextures() {
    textureManager.load("player_walk", "assets/sprites/player_walk.png");
}

Game* Game::getInstance()
{
    if(instance == 0) {
        instance = new Game();
    }
        
    return instance;
}

StateManager* Game::getStateManager() {
    return stateManager;
}

TextureManager& Game::getTextureManager() {
    return textureManager;
}

void Game::run() {
    float elapsedTime = 0.f;
    float percentTick = 0.f;

    while(running && engine2D->isOpen()) {
        currentState = stateManager->getCurrentState();
        
        handleInput();

        elapsedTime = clock.getElapsedTime();

        if (elapsedTime >= updateTime) {
            update(updateTime);
            clock.restart();
            elapsedTime = 0.f;
        }

        percentTick = min(1.f, elapsedTime / updateTime);
        
        render(percentTick);

        if (inputManager.isQuitRequested()) {
            quit();
        }
        stateManager->processPending();
    }
}

void Game::handleInput() {
    inputManager.pollEvents(engine2D->getGraphicEngine());
    currentState->handleInput(inputManager);
}

void Game::update(float dt) {
    currentState->update(dt);

    Vector2 target = currentState->getCameraTarget();
    Camera& camera = engine2D->getCamera();
    
    Vector2 currentPosition = camera.getPosition();
    Vector2 newPosition;
    newPosition.x = currentPosition.x + (target.x - currentPosition.x) * smoothFactor;
    newPosition.y = currentPosition.y + (target.y - currentPosition.y) * smoothFactor;
    camera.setPosition(newPosition.x, newPosition.y);
}

void Game::render(float alpha) {
    engine2D->beginFrame();
    currentState->render(engine2D, alpha);
    engine2D->endFrame();
}

void Game::quit() {
    running = false;
}
