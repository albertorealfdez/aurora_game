#include <iostream>
#include "MySprite.h"

MySprite::MySprite() {
    
}

const sf::Sprite& MySprite::getSFMLSprite() const {
    return sprite;
}

void MySprite::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}

void MySprite::move(float dx, float dy) {
    sprite.move(dx, dy);
}

void MySprite::setTexture(Texture* tex) {
    // Convertimos a SFMLTexture
    SFMLTexture* sfTexture = dynamic_cast<SFMLTexture*>(tex);

    if (sfTexture) {
        sprite.setTexture(sfTexture->getSFMLTexture());
    }
}

const Texture* MySprite::getTexture() const {
    return texture;
}

void MySprite::setScale(float x, float y) {
    sprite.setScale(x, y);
}

void MySprite::setOrigin(float x, float y) {
    sprite.setOrigin(x, y);
}

void MySprite::setTextureRect(int x, int y, int w, int h) {
    sprite.setTextureRect(sf::IntRect(x, y, w, h));
}

Rect MySprite::getGlobalBounds() {
    sf::FloatRect bounds = sprite.getGlobalBounds();

    return Rect(bounds.left, bounds.top, bounds.width, bounds.height);
}