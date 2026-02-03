#include "Game.h"
#include "IntroState.h"

Game* Game::instance = 0;

Game::Game() {
    engine2D = new Engine2D();
    stateManager = new StateManager();
    stateManager->pushState(new IntroState(this));
    stateManager->processPending();

    running = true;
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
    while(running && engine2D->isOpen()) {
        State* currentState = stateManager->getCurrentState();
        
        inputManager.pollEvents(engine2D->getGraphicEngine());

        currentState->handleInput(inputManager);
        currentState->update();

        engine2D->beginFrame();
        currentState->render(engine2D);
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
