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
}

Game* Game::getInstance()
{
    if(instance == 0) {
        instance = new Game();
    }
        
    return instance;
}

void Game::run() {
    while(isRunning) {
        stateManager->getCurrentState()->handleEvents();
        stateManager->getCurrentState()->update();
        stateManager->getCurrentState()->render(engine2D);

        if (!engine2D->isOpen()) {
            isRunning = false;
        }
    }
}

void Game::quit() {
    isRunning = false;
}
