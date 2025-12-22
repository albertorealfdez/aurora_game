#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class GameState {
    public:
        virtual void init() = 0;
        virtual void handleEvents() = 0;
        virtual void update() = 0;
        virtual void render() = 0;
};

#endif /* STATE_H */