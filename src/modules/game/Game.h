#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "Engine2D.h"
#include "StateManager.h"

using namespace std;

class Game {
    private:
        static Game* instance;
        Engine2D* engine2D;
        StateManager* stateManager;
        
        bool isRunning;
        Game();

    public:
        ~Game();

        static Game* getInstance();
        void run();
        void quit();
};

#endif /* GAME_H */