#include "StateManager.h"

StateManager::StateManager() {

}

StateManager::~StateManager() {
    delete currentState;
}

State* StateManager::getCurrentState() const {
    return currentState;
}

void StateManager::changeState(State* state) {
    if (currentState)
        delete currentState;

    currentState = state;
}