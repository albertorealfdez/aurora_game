#include <iostream>
#include "MySprite.h"

MySprite::MySprite() {
    
}

const sf::Sprite& MySprite::getSprite() const {
    return sprite;
}

void MySprite::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}

void MySprite::move(float dx, float dy) {
    sprite.move(dx, dy);
}

void MySprite::setTexture(const sf::Texture& texture) {
    sprite.setTexture(texture);
}

const sf::Texture* MySprite::getTexture() const {
    return sprite.getTexture();
}

void MySprite::setScale(float x, float y) {
    sprite.setScale(x, y);
}

void MySprite::setTextureRect(int x, int y, int w, int h) {
    sprite.setTextureRect(sf::IntRect(x, y, w, h));
}
