#ifndef SOLDIER_H
#define SOLDIER_H

#include "Unit.h"

class Soldier: public Unit {
    public:
        Soldier(Vector2 initialPostion);
        void init(Engine2D* engine2D) override;
        void update(float dt) override;
        void render(Engine2D* engine2D, float alpha) override;
};

#endif /* SOLDIER_H */