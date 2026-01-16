#ifndef GAME_H
#define GAME_H

#include "Engine2D.h"
#include <iostream>

using namespace std;

class Game {
    private:
        static Game *instance;
        Engine2D *engine2D;
        
        bool isRunning;
        Game();

    public:
        ~Game();

        static Game* getInstance();
        void run();
};

#endif /* GAME_H */