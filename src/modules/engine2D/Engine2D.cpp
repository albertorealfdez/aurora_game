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

void Engine2D::drawText(const string& text, float x, float y, unsigned size) {
    graphics->clear();
    graphics->drawText(text, x, y, size);
    graphics->display();
}
