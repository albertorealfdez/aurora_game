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

    Vector2 operator-(const Vector2 &vec2)
    {
        return Vector2(x - vec2.x, y - vec2.y);
    }

    bool operator==(const Vector2 &vec2)
    {
        return (x == vec2.x && y == vec2.y);
    }
};

#endif /* VECTOR2_H */
