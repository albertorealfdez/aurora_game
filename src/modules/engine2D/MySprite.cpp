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

void MySprite::setTexture(const string& path) {
    
    if (!texture.loadFromFile(path)) {
        cout<< "Error cargando la imagen sprites.png"<<endl;
    } else {
        cout<<"Texture loaded"<<endl;
    }
    sprite.setTexture(texture);
}

void MySprite::setScale(float x, float y) {
    sprite.setScale(x, y);
}

void MySprite::setTextureRect(int x, int y, int w, int h) {
    sprite.setTextureRect(sf::IntRect(x, y, w, h));
}
