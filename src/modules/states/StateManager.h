#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include "State.h"

using namespace std;

class StateManager {
    private:
        vector<State*> states;

    public: 
        StateManager();
        ~StateManager();

        State* getCurrentState() const;
        void changeState(State* state);
        void pushState(State* state);
};

#endif /* STATE_MANAGER_H */