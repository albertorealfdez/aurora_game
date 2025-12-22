#include "Game.h"

Game* Game::instance = 0;


Game::Game() {
    running = true;
}

Game* Game::getInstance()
{
    if(instance == 0) {
        instance = new Game();
    }
        
    return instance;
}

bool Game::isRunning() {
    return running;
}