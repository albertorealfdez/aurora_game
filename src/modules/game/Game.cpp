#include "Game.h"
#include "IntroState.h"

Game* Game::instance = 0;

Game::Game() {
    engine2D = new Engine2D();
    stateManager = new StateManager();
    stateManager->pushState(new IntroState(this));
    stateManager->processPending(engine2D);

    running = true;
    limitRender = true;
    renderFPS = 60;
    updateTime = 1.f/15.f;

    engine2D->loadFont("title", "./assets/fonts/Cinzel-Regular.ttf");
}

Game::~Game() {
    delete engine2D;
    delete stateManager;
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
        stateManager->processPending(engine2D);
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
    camera.update(dt, target);
}

void Game::render(float alpha) {
    engine2D->beginFrame();
    currentState->render(engine2D, alpha);
    engine2D->endFrame();
}

void Game::quit() {
    running = false;
}
