#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>
#include "InputManager.h"

static Key fromSFMLKey(sf::Keyboard::Key sfKey) {
    Key key;

    switch (sfKey)
    {
        case sf::Keyboard::Space:
            key = Key::Space;
            break;
        case sf::Keyboard::Escape:
            key = Key::Escape;
            break;
        
        default:
            key = Key::Unknown;
            break;
    }
    return key;
}
/*
void InputManager::pollEvents(SFMLGraphicEngine& graphics) {
    previousKeys = currentKeys;

    sf::Event event;
    while (graphics->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            cout<<"Close!"<<endl;
        }
        else if (event.type == sf::Event::isKeyPressed) {
            currentKeys[fromSFMLKey(event.key.code)] = true;
        }
        else if (event.type == sf::Event::isKeyReleased) {
            currentKeys[fromSFMLKey(event.key.code)] = false;
        }
    }
}*/

bool InputManager::isKeyDown(Key key) {
    return currentKeys[key];
}

bool InputManager::isKeyPressed(Key key) {
    return isKeyDown(key) && !previousKeys[key];
}


bool InputManager::isKeyReleased(Key key) {
    return !isKeyDown(key) && previousKeys[key];
}