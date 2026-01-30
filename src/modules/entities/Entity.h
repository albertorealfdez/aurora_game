#ifndef ENTITY_H
#define ENTITY_H

#include "InterpolatedPosition.h"
#include "MySprite.h"

class Entity {
    protected:
        InterpolatedPosition position;
        MySprite mySprite;

    public:
        virtual void init() = 0;
        virtual MySprite getMySprite() = 0;
};

#endif /* ENTITY_H */