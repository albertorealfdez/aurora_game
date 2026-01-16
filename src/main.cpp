#include <SFML/Graphics.hpp>
#include <iostream>

#include "Game.h"

int main() {
    Game *game = Game::getInstance();
    game->run();
    return 0;
}