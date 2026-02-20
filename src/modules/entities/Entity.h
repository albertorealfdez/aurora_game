#ifndef ENTITY_H
#define ENTITY_H

#include "InputManager.h"
#include "InterpolatedPosition.h"
#include "Engine2D.h"
#include "MySprite.h"
#include "Animator.h"

class Entity {
    protected:
        float speed;
        InterpolatedPosition position;
        MySprite mySprite;
        Animator* animator;

    public:
        virtual void init(Engine2D* engine2D) = 0;
        virtual MySprite& getMySprite() = 0;
        virtual Vector2 getCurrentPosition() = 0;
        virtual float getSpeed() = 0;
        virtual void setSpeed(float speed) = 0;

        virtual void handleInput(InputManager& inputManager) = 0;
        virtual void update(float dt) = 0;
        virtual void render(Engine2D* engine2D, float alpha) = 0;
        
};

#endif /* ENTITY_H */