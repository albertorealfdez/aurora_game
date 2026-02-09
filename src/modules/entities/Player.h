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
        Player(ResourceManager<Texture>& tm);
        
        void init() override;

        MySprite& getMySprite() override;
        Vector2 getCurrentPosition() override;

        float getSpeed();
        void setSpeed(float speed);
        void setState(PlayerState newState);
        
        void handleInput(InputManager& inputManager) override;
        void update(float dt) override;
        void render(Engine2D* engine2D, float alpha) override;
    private:
        float speed;
        Animator* animator;
        PlayerState state;
};

#endif /* PLAYER_H */
