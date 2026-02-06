#ifndef MYSPRITE_H
#define MYSPRITE_H

#include <string>
#include <SFML/Graphics.hpp>

using namespace std;

class MySprite {
    private:
        sf::Sprite sprite;
        sf::Texture texture;
        
    public:
        MySprite();

        const sf::Sprite& getSprite() const;
        void setPosition(float x, float y);
        void move(float dx, float dy);
        void setTexture(const sf::Texture& texture);
        const sf::Texture* getTexture() const;
        void setScale(float x, float y);
        void setOrigin(float x, float y);
        void setTextureRect(int x, int y, int w, int h);

};  

#endif /* MYSPRITE_H */