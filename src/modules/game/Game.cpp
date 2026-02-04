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

void Game::run() {
    float elapsedTime = 0.f;
    float percentTick = 0.f;

    while(running && engine2D->isOpen()) {
        State* currentState = stateManager->getCurrentState();
        
        inputManager.pollEvents(engine2D->getGraphicEngine());
        currentState->handleInput(inputManager);

        elapsedTime = clock.getElapsedTime();

        if (elapsedTime >= updateTime) {
            currentState->update(updateTime);
            clock.restart();
            elapsedTime = 0.f;
        }

        percentTick = min(1.f, elapsedTime / updateTime);
        
        engine2D->beginFrame();
        currentState->render(engine2D, percentTick);
        engine2D->endFrame();

        if (inputManager.isQuitRequested()) {
            quit();
        }
        stateManager->processPending();
    }
}

void Game::quit() {
    running = false;
}
