#include "SFMLFont.h"

bool SFMLFont::loadFromFile(const string& path) {
    return font.loadFromFile(path);
}

int SFMLFont::getSize() const {
    return size;
}

void SFMLFont::setSize(int newSize) {
    size = newSize;
}


const sf::Font& SFMLFont::getSFMLFont() const {
    return font;
}