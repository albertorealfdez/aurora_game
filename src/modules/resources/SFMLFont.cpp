#include "SFMLFont.h"

bool SFMLFont::loadFromFile(const string& path) {
    return font.loadFromFile(path);
}

const sf::Font& SFMLFont::getSFMLFont() const {
    return font;
}