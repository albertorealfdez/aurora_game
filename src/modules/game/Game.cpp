#include "Game.h"
#include "IntroState.h"

Game* Game::instance = 0;

Game::Game() {
    engine2D = new Engine2D();
    stateManager = new StateManager();
    stateManager->pushState(new IntroState(this));

    isRunning = true;
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
    while(isRunning && engine2D->isOpen()) {
        State* currentState = stateManager->getCurrentState();

        currentState->handleInput();
        currentState->update();
        currentState->render(engine2D);

        if (!engine2D->isOpen()) {
            isRunning = false;
        }
    }
}

void Game::quit() {
    isRunning = false;
}
