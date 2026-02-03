#ifndef MYSPRITE_H
#define MYSPRITE_H

#include <string>
#include <SFML/Graphics.hpp>

using namespace std;

class MySprite {
    private:
        sf::Sprite sprite;
        sf::Texture texture;
        int frameWidth;
        int frameHeight;
        
    public:
        MySprite();
        ~MySprite();

        const sf::Sprite& getSprite() const;
        void setPosition(float x, float y);
        void move(float dx, float dy);
        void setTexture(const string& path);
        void setFrame(int row, int col);
        void setScale(float x, float y);
        void setTextureRect(int x, int y, int w, int h);
        void setFrameHeight(int height);
        void setFrameWidth(int width);

};  

#endif /* MYSPRITE_H */