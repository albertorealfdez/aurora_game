#ifndef MYTEXT_H
#define MYTEXT_H

#include <string>
#include <SFML/Graphics.hpp>
#include "Font.h"
#include "Vector2.h"

using namespace std;

class MyText {
    private:
        string text;
        int size;
        Vector2 position;
        Font* font;
        sf::Text sfText;

    public:
        void setText(const string& content);
        const string& getText() const;
        void setSize(int px);
        int getSize() const;
        void setPosition(float x, float y);
        Vector2 getPosition() const;
        void setFont(Font* font);
        Font* getFont() const;

        const sf::Text& getSFMLText() const;

};

#endif /* MYTEXT_H */