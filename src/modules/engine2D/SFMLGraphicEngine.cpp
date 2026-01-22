#include "SFMLGraphicEngine.h"

SFMLGraphicEngine::SFMLGraphicEngine() {
    window = new sf::RenderWindow(sf::VideoMode(800, 600), "Aurora Game");

    if (!font.loadFromFile("./assets/fonts/arial.ttf")) {
        throw std::runtime_error("Error loading font");
    }
}

SFMLGraphicEngine::~SFMLGraphicEngine() {
    if (window->isOpen()) {
        window->close();
    }

    delete window;
}

bool SFMLGraphicEngine::isOpen() {
    return window->isOpen();
}
/*
bool SFMLGraphicEngine::pollEvent(sf::Event& event) {
    return window->pollEvent(event);
}*/


void SFMLGraphicEngine::clear() {
    sf::Event event;
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();
    }
    window->clear(sf::Color::Black);
}

void SFMLGraphicEngine::display() {
    window->display();
}

void SFMLGraphicEngine::drawText(const string& text, float x, float y, unsigned size) {
    sf::Text drawableText;
    drawableText.setFont(font);
    drawableText.setString(text);
    drawableText.setCharacterSize(size);
    drawableText.setFillColor(sf::Color::White);
    drawableText.setPosition(x, y);

    window->draw(drawableText);
}