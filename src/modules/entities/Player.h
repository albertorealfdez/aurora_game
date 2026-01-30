#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player: public Entity {
    public:
        Player();

        void init() override;
        MySprite& getMySprite() override;

        float getSpeed();
        void setSpeed(float speed);

    private:
        float speed;
};

#endif /* PLAYER_H */