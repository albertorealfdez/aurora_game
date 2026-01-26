#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include<unordered_map>        
#include "Key.h"
#include "GraphicEngine.h"

using namespace std;

class InputManager {
    private:
        unordered_map<Key, bool> currentKeys;
        unordered_map<Key, bool> previousKeys;
        bool quitRequested;
        
    public:
        void pollEvents(GraphicEngine& graphics);
        bool isQuitRequested();
        bool isKeyDown(Key key);
        bool isKeyPressed(Key key);
        bool isKeyReleased(Key key);
};


#endif /* INPUT_MANAGER_H */