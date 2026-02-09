#include "SFMLTexture.h"

bool SFMLTexture::loadFromFile(const string& path) {
    return texture.loadFromFile(path);
}


const sf::Texture& SFMLTexture::getSFMLTexture() const {
    return texture;
}

int SFMLTexture::getWidth() const {
    return texture.getSize().x;
}

int SFMLTexture::getHeight() const {
    return texture.getSize().y;
}