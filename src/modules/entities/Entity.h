#ifndef ENTITY_H
#define ENTITY_H

#include "InputManager.h"
#include "InterpolatedPosition.h"
#include "MySprite.h"
#include "Engine2D.h"

class Entity {
    protected:
        InterpolatedPosition position;
        MySprite mySprite;

    public:
        virtual void init(Engine2D* engine2D) = 0;
        virtual MySprite& getMySprite() = 0;
        virtual Vector2 getCurrentPosition() = 0;

        virtual void handleInput(InputManager& inputManager) = 0;
        virtual void update(float dt) = 0;
        virtual void render(Engine2D* engine2D, float alpha) = 0;
        
};

#endif /* ENTITY_H */