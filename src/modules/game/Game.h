#ifndef GAME_H
#define GAME_H

#include "Engine2D.h"
#include "StateManager.h"
#include "InputManager.h"
#include "Clock.h"

class Game {
    private:
        static Game* instance;
        Engine2D* engine2D;
        StateManager* stateManager;
        InputManager inputManager;
        Clock clock;
        
        bool limitRender;
        int renderFPS;
        float updateTime;
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