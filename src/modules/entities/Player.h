#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

enum class PlayerState {
    Idle,
    WalkRight,
    WalkDown,
    WalkLeft,
    WalkUp
};

class Player: public Entity {
    private:
        PlayerState state;
        int dx;
        int dy;
        float speed;
        float health;

    public:
        Player(Vector2 initialPostion);
        
        void init(Engine2D* engine2D) override;
        MySprite& getMySprite() override;
        Vector2 getCurrentPosition() override;

        float getSpeed();
        void setSpeed(float speed);
        void setState(PlayerState newState);
        Vector2 getNextPosition();
        void applyMovement();
        
        void handleInput(InputManager& inputManager);
        void update(float dt) override;
        void render(Engine2D* engine2D, float alpha) override;
};

#endif /* PLAYER_H */
