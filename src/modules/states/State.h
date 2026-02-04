#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Engine2D.h"
#include "InputManager.h"

using namespace std;

class Game;

class State {
    protected:
        Game* game;

    public:
        State(Game* game): game(game) {}
        virtual ~State() = default;

        virtual void init() = 0;
        virtual void handleInput(InputManager& inputManager) = 0;
        virtual void update(float dt) = 0;
        virtual void render(Engine2D* engine2D, float alpha) = 0;
};

#endif /* STATE_H */