#ifndef ENTITY_H
#define ENTITY_H

#include "InputManager.h"
#include "InterpolatedPosition.h"
#include "MySprite.h"

class Entity {
    protected:
        InterpolatedPosition position;
        MySprite mySprite;

    public:
        virtual void init() = 0;
        virtual MySprite& getMySprite() = 0;
        virtual void handleInput(InputManager& inputManager) = 0;
        virtual void update() = 0;
        
};

#endif /* ENTITY_H */