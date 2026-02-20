#ifndef MYSPRITE_H
#define MYSPRITE_H

#include <string>
#include <SFML/Graphics.hpp>
#include "Texture.h"
#include "SFMLTexture.h"
#include "Rect.h"

using namespace std;

class MySprite {
    private:
        sf::Sprite sprite;
        Texture* texture;
        
    public:
        MySprite();

        const sf::Sprite& getSFMLSprite() const;
        void setPosition(float x, float y);
        void move(float dx, float dy);
        void setTexture(Texture* tex);
        const Texture* getTexture() const;
        void setScale(float x, float y);
        void setOrigin(float x, float y);
        void setTextureRect(int x, int y, int w, int h);
        Rect getGlobalBounds();

};  

#endif /* MYSPRITE_H */