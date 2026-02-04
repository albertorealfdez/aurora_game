#include "Event.h"
#include "InputManager.h"

void InputManager::pollEvents(GraphicEngine& graphics) {
    previousKeys = currentKeys;

    Event event;
    while (graphics.pollEvent(event)) {
        if (event.type == EventType::Closed) {
            quitRequested = true;
        }
        else if (event.type == EventType::KeyPressed) {
            currentKeys[event.key] = true;
        }
        else if (event.type == EventType::KeyReleased) {
            currentKeys[event.key] = false;
        }
    }
}

bool InputManager::isQuitRequested() {
    return quitRequested;
}

bool InputManager::isKeyDown(Key key) {
    return currentKeys[key];
}

bool InputManager::isKeyPressed(Key key) {
    return isKeyDown(key) && !previousKeys[key];
}


bool InputManager::isKeyReleased(Key key) {
    return !isKeyDown(key) && previousKeys[key];
}