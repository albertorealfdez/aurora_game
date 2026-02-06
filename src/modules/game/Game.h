#ifndef GAME_H
#define GAME_H

#include "Engine2D.h"
#include "Clock.h"
#include "StateManager.h"
#include "InputManager.h"
#include "TextureManager.h"

class Game {
    private:
        static Game* instance;
        Engine2D* engine2D;
        StateManager* stateManager;
        InputManager inputManager;
        TextureManager textureManager;
        Clock clock;
        
        bool limitRender;
        int renderFPS;
        float updateTime;
        bool running;

        Game();
        void loadTextures();

    public:
        ~Game();

        static Game* getInstance();
        StateManager* getStateManager();
        TextureManager& getTextureManager();
        void run();
        void quit();

};

#endif /* GAME_H */