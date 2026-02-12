#ifndef SFMLFONT_H
#define SFMLFONT_H

#include <SFML/Graphics/Font.hpp>
#include <string>
#include "Font.h"

using namespace std;

class SFMLFont: public Font {
    private: 
        sf::Font font;
    public:
        bool loadFromFile(const string& path);
        const sf::Font& getSFMLFont() const;
};

#endif /* SFMLFONT_H */