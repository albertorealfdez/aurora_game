#include "StateManager.h"

StateManager::StateManager() {
    
}

StateManager::~StateManager() {
    for (State* state: states) {
        delete state;
    }
    states.clear();
}

State* StateManager::getCurrentState() const {
    if (states.empty()) {
        return NULL;
    }

    return states.back();
}

void StateManager::changeState(State* state) {
    cout<<"Changing state!"<<endl;
}

void StateManager::pushState(State* state) {
    states.push_back(state);
    states.back()->init();
}

