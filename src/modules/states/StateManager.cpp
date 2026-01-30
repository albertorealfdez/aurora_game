#include "StateManager.h"

StateManager::StateManager() {
    
}

StateManager::~StateManager() {
    for (State* state: states) {
        delete state;
    }
    states.clear();

    delete pendingState;
}

State* StateManager::getCurrentState() const {
    if (states.empty()) {
        return NULL;
    }

    return states.back();
}

void StateManager::changeState(State* state) {
    isChanging = true;
    isPushing = true;
    pendingState = state;
}

void StateManager::popState() {
    delete states.back();
    states.pop_back();
}

void StateManager::pushState(State* state) {
    isPushing = true;
    pendingState = state;
}

void StateManager::processPending() {
    if (isChanging) {
        popState();
        isChanging = false;
    }

    if (isPushing) {
        states.push_back(pendingState);
        states.back()->init();
        isPushing = false;
        pendingState = nullptr;
    }
}

