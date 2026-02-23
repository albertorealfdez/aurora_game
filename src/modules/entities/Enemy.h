#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"
#include "Animator.h"

enum class EnemyState {
    Idle,
    WalkRight,
    WalkDown,
    WalkLeft,
    WalkUp
};

class Enemy: public Entity {
    private:
        EnemyState state;
        
    public:
        Enemy();

        void init(Engine2D* engine2D) override;
        MySprite& getMySprite() override;
        Vector2 getCurrentPosition() override;
        float getSpeed() override;
        void setSpeed(float speed) override;

        void setState(EnemyState newState);

        void handleInput(InputManager& inputManager) override;
        void update(float dt) override;
        void render(Engine2D* engine2D, float alpha) override;
};

#endif /* ENEMY_H */