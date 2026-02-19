#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Animator.h"

enum class PlayerState {
    Idle,
    WalkRight,
    WalkDown,
    WalkLeft,
    WalkUp
};

class Player: public Entity {
    public:
        Player();
        
        void init(Engine2D* engine2D) override;
        MySprite& getMySprite() override;
        Vector2 getCurrentPosition() override;

        float getSpeed();
        void setSpeed(float speed);
        void setState(PlayerState newState);
        Vector2 getNextPosition();
        void applyMovement();
        
        void handleInput(InputManager& inputManager) override;
        void update(float dt) override;
        void render(Engine2D* engine2D, float alpha) override;
    private:
        float speed;
        Animator* animator;
        PlayerState state;
        int dx;
        int dy;
};

#endif /* PLAYER_H */
