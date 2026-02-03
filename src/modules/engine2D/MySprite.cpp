#include <iostream>
#include "MySprite.h"

MySprite::MySprite() {
    //sprite = new sf::Sprite();
    //texture = new sf::Texture();
}

MySprite::~MySprite() {
    //delete sprite;
    //delete texture;
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

void MySprite::setFrame(int row, int col) {
    setTextureRect(col * frameWidth, row * frameHeight, frameWidth, frameHeight);
}

void MySprite::setScale(float x, float y) {
    sprite.setScale(x, y);
}

void MySprite::setTextureRect(int x, int y, int w, int h) {
    sprite.setTextureRect(sf::IntRect(x, y, w, h));
}

void MySprite::setFrameHeight(int height) {
    frameHeight = height;
}

void MySprite::setFrameWidth(int width) {
    frameWidth = width;
}