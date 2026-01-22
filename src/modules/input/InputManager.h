#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include<unordered_map>        
#include "Key.h"

using namespace std;

class InputManager {
    private:
        unordered_map<Key, bool> currentKeys;
        unordered_map<Key, bool> previousKeys;
        
    public:
        //void pollEvents(Engine2D& engine);
        bool isKeyDown(Key key);
        bool isKeyPressed(Key key);
        bool isKeyReleased(Key key);
};


#endif /* INPUT_MANAGER_H */