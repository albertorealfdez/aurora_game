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

        void init() override;
        void handleInput(InputManager& inputManager) override;
        void update(float dt) override;
        void render(Engine2D* engine2D, float alpha) override;


        MySprite& getMySprite() override;
        float getSpeed();
        void setSpeed(float speed);
        void setState(PlayerState newState);
        
    private:
        float speed;
        Animator* animator;
        PlayerState state;
        float x; // Temporal
        float y; // Temporal
};

#endif /* PLAYER_H */
