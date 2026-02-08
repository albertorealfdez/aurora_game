#ifndef VECTOR2_H
#define VECTOR2_H

struct Vector2 {
    float x;
    float y;

    Vector2() =  default;
    Vector2(float newX, float newY) {
        x = newX;
        y = newY;
    }
};

#endif /* VECTOR2_H */
