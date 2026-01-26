#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "Engine2D.h"
#include "StateManager.h"
#include "InputManager.h"

using namespace std;

class Game {
    private:
        static Game* instance;
        Engine2D* engine2D;
        StateManager* stateManager;
        InputManager inputManager;
        
        bool running;
        Game();

    public:
        ~Game();

        static Game* getInstance();
        void run();
        void quit();

        StateManager* getStateManager() { return stateManager; }
};

#endif /* GAME_H */