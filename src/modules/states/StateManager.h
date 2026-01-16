#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include "State.h"

class StateManager {
    private:
        State* currentState;

    public: 
        StateManager();
        ~StateManager();

        State* getCurrentState() const;
        void changeState(State* state);
};

#endif /* STATE_MANAGER_H */