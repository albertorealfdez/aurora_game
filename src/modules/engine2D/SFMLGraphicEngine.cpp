#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>

#include "SFMLGraphicEngine.h"
#include "MySprite.h"

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

static Key fromSFMLKey(sf::Keyboard::Key sfKey) {
    Key key;

    switch (sfKey)
    {
        case sf::Keyboard::Escape:
            key = Key::Escape;
            break;

        case sf::Keyboard::W:
            key = Key::W;
            break;
        case sf::Keyboard::A:
            key = Key::A;
            break;
        case sf::Keyboard::S:
            key = Key::S;
            break;
        case sf::Keyboard::D:
            key = Key::D;
            break;
        

        case sf::Keyboard::Space:
            key = Key::Space;
            break;

        default:
            key = Key::Unknown;
            break;
    }
    return key;
}

bool SFMLGraphicEngine::isOpen() {
    return window->isOpen();
}

bool SFMLGraphicEngine::pollEvent(Event& event) {
    sf::Event sfEvent;

    if (window->pollEvent(sfEvent)) {
        switch(sfEvent.type) {
            case sf::Event::Closed:
                event.type = EventType::Closed;
                break;
            case sf::Event::KeyPressed:
                event.type = EventType::KeyPressed;
                event.key = fromSFMLKey(sfEvent.key.code);
                break;
            case sf::Event::KeyReleased:
                event.type = EventType::KeyReleased;
                event.key = fromSFMLKey(sfEvent.key.code);
                break;
            default:
                event.type = EventType::None;
                event.key = Key::Unknown;
                break;
        }
        return true;
    }
    return false;
}


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

void SFMLGraphicEngine::drawSprite(const MySprite& mySprite) {
    window->draw(mySprite.getSprite());
}