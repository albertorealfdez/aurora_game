#ifndef SFMLTEXTURE_H
#define SFMLTEXTURE_H

#include <SFML/Graphics/Texture.hpp>
#include <string>
#include "Texture.h"

using namespace std;

class SFMLTexture: public Texture {
    private:
        sf::Texture texture;

    public:
        bool loadFromFile(const string& path);
        const sf::Texture& getSFMLTexture() const;

        int getWidth() const override;
        int getHeight() const override;
};

#endif /* SFMLTEXTURE_H */