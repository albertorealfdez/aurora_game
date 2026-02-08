#include "Engine2D.h"

Engine2D::Engine2D() {
    graphics = new SFMLGraphicEngine();
    camera.setSize(640, 360);
    camera.setPosition(640/2, 360/2);
    camera.setZoom(1.f);
}

Engine2D::~Engine2D() {
    delete graphics;
}

GraphicEngine& Engine2D::getGraphicEngine() {
    return *graphics;
}

bool Engine2D::isOpen() {
    return graphics->isOpen();
}

void Engine2D::beginFrame() {
    graphics->setCamera(camera);
    graphics->clear();
}

void Engine2D::endFrame() {
    graphics->display();
}

void Engine2D::drawText(const string& text, float x, float y, unsigned size) {
    graphics->drawText(text, x, y, size);
}

void Engine2D::drawSprite(const MySprite& mySprite) {
    graphics->drawSprite(mySprite);
}
