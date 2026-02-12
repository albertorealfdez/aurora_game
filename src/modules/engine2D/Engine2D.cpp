#include "Engine2D.h"

Engine2D::Engine2D() {
    graphics = new SFMLGraphicEngine();
    camera.setSize(1280, 720); // TODO: move to constant/config
    camera.setPosition(1280/2.f, 720/2.f);
    camera.setZoom(1.f);
    camera.setSmooth(0.1f);
}

Engine2D::~Engine2D() {
    delete graphics;
}

GraphicEngine& Engine2D::getGraphicEngine() {
    return *graphics;
}

Camera& Engine2D::getCamera() {
    return camera;
}

bool Engine2D::isOpen() {
    return graphics->isOpen();
}

void Engine2D::loadTexture(const string& id, const string& path) {
    resources.textureManager.load(id, path);
}

Texture* Engine2D::getTexture(const string& id) {
    return resources.textureManager.get(id);
}

void Engine2D::loadFont(const string& id, const string& path) {
    resources.fontManager.load(id, path);
}

Font* Engine2D::getFont(const string& id) {
    return resources.fontManager.get(id);
}

void Engine2D::beginFrame() {
    graphics->setCamera(camera);
    graphics->clear();
}

void Engine2D::endFrame() {
    graphics->display();
}

void Engine2D::drawText(MyText myText) {
    graphics->drawText(myText);
}

void Engine2D::drawSprite(const MySprite& mySprite) {
    graphics->drawSprite(mySprite);
}
