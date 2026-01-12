#ifndef GAME_H
#define GAME_H

#include <iostream>
using namespace std;

class Game {
    private:
        static Game *instance;
        
        bool running;
        Game();

    public:
        static Game* getInstance();
        void run();
};

#endif /* GAME_H */