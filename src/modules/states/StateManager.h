#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include "State.h"

using namespace std;

class StateManager {
    private:
        vector<State*> states;
        
        bool isChanging;
        bool isPushing;
        State* pendingState;

    public: 
        StateManager();
        ~StateManager();

        State* getCurrentState() const;
        void changeState(State* state);
        void popState();
        void pushState(State* state);
        void processPending(Engine2D* engine2D);
};

#endif /* STATE_MANAGER_H */