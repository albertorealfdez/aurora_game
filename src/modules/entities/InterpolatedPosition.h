struct Vector2 {
    float x;
    float y;

    Vector2() =  default;
    Vector2(float newX, float newY) {
        x = newX;
        y = newY;
    }
};

class InterpolatedPosition {
    public:
        // TODO: move to private?
        Vector2 current;
        Vector2 last;

        void set(float x, float y) {
            last = current;
            current = Vector2(x, y);
        }

        Vector2  interpolate(float alpha) const {
            float newX = last.x * (1.f - alpha) + current.x  * alpha;
            float newY = last.y * (1.f - alpha) + current.y  * alpha;

            return Vector2(newX, newY);
        }
};