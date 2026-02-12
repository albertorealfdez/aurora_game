#include <SFML/Graphics/Font.hpp>
#include <string>
#include "Font.h"

using namespace std;

class SFMLFont: public Font {
    private: 
        sf::Font font;
        int size=16;
    public:
        bool loadFromFile(const string& path);
        int getSize() const override;
        void setSize(int newSize) override;
        const sf::Font& getSFMLFont() const;
};