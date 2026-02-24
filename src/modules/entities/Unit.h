#ifndef UNIT_H
#define UNIT_H

#include "Entity.h"
#include "Animator.h"

enum class UnitState {
    Idle,
    WalkRight,
    WalkDown,
    WalkLeft,
    WalkUp
};

class Unit: public Entity {
    protected:
        UnitState state;
        int dx;
        int dy;
        float speed;
        float health;

    public:
        Unit(Vector2 initialPostion);

        virtual void init(Engine2D* engine2D) override = 0;
        MySprite& getMySprite() override;
        Vector2 getCurrentPosition() override;

        float getSpeed();
        void setSpeed(float speed);
        void setState(UnitState newState);

        virtual void update(float dt) override = 0;
        virtual void render(Engine2D* engine2D, float alpha) override = 0;
};

#endif /* UNIT_H */