#include <iostream>
#include "TextureManager.h"

void TextureManager::load(const string& name, const string& filename) {
    sf::Texture texture;

    if (!texture.loadFromFile(basePath + filename)) {
        cerr<<"Failed to load texture: " + filename<<endl; // TODO: change to exceptions
    }
    textures[name] = texture;
}

sf::Texture* TextureManager::get(const string& name) {
    if (textures.count(name)) {
        return &textures[name];
    }
    return nullptr;

}