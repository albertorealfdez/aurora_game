#include "Engine2D.h"

Engine2D::Engine2D() {
    graphics = new SFMLGraphicEngine();
}

void Engine2D::run() {
    while (graphics->isOpen())
    {
        //inputManager.update();

        //state->handleInput(inputManager);
        //state->update(0.016f);

        graphics->clear();
        //state->render(*graphics);
        graphics->display();
        
    }
}