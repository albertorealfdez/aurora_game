#include "Engine2D.h"

Engine2D::Engine2D() {
    graphics = new SFMLGraphicEngine();
}

Engine2D::~Engine2D() {
    delete graphics;
}

bool Engine2D::isOpen() {
    return graphics->isOpen();
}

void Engine2D::test() {
    graphics->clear();
    graphics->drawText("Hello", 100, 200, 32);
    graphics->display();
}
/*
bool pollEvent(Event& event) {
    return 
}*/