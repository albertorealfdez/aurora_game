struct Vector2 {
    float x;
    float y;
};

class InterpolatedPosition {
    private:
        Vector2 position;
        Vector2 lastPosition;

    public:
        Vector2 getPostion() {
            return position;
        }

        Vector2 getLastPosition() {
            return lastPosition;
        }

        void set(float x, float y) {
            position.x = x;
            position.y = y;
        }
};