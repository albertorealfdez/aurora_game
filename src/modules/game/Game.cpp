#include "Game.h"

Game* Game::instance = 0;


Game::Game() {
    engine2D = new Engine2D();
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
        // handleInput()
        // update()
        // render
        engine2D->test();
    }
}
