#include "MyText.h"
#include "SFMLFont.h"

#include <iostream>

void MyText::setText(const string& content) {
    text = content;
    sfText.setString(text);
}

const string& MyText::getText() const {
    return text;
}

void MyText::setSize(int px) {
    size = px;
    sfText.setCharacterSize(size);

}

int MyText::getSize() const {
    return size;
}

void MyText::setPosition(float x, float y) {
    position = {x, y};
    sfText.setPosition(x, y);
}

Vector2 MyText::getPosition() const {
    return position;
}

void MyText::setFont(Font* baseFont) {
    font = baseFont;

    SFMLFont* sfFont = dynamic_cast<SFMLFont*>(font);
    
    if (sfFont) {
        sfText.setFont(sfFont->getSFMLFont());
        sfText.setFillColor(sf::Color::White);
    }
}

Font* MyText::getFont() const {
    return font;
}

const sf::Text& MyText::getSFMLText() const {
    return sfText;
}