#include <SFML/Window/Keyboard.hpp>

#include "InputManager.h"

static sf::Keyboard::Key toSFMLKey(Key key) {
    sf::Keyboard::Key sfKey;

    switch (key)
    {
        case Key::Space:
            sfKey = sf::Keyboard::Space;
            break;
        case Key::Escape:
            sfKey = sf::Keyboard::Escape;
            break;
        
        default:
            sfKey = sf::Keyboard::Unknown;
            break;
    }
    return sfKey;
}

bool InputManager::isKeyPressed(Key key) {
    return sf::Keyboard::isKeyPressed(toSFMLKey(key));
}