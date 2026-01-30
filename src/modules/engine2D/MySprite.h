#ifndef MYSPRITE_H
#define MYSPRITE_H

#include <string>
using namespace std;

namespace sf {
    class Sprite;
    class Texture;
}

class MySprite {
    private:
        sf::Sprite* sprite;
        sf::Texture* texture;

    public:
        MySprite();
        ~MySprite();

        const sf::Sprite& getSprite() const;
        void setPosition(float x, float y);
        void move(float dx, float dy);
        void setTexture(const string& path);
        void setScale(float x, float y);
        void setTextureRect(int x, int y, int w, int h);

};  

#endif /* MYSPRITE_H */