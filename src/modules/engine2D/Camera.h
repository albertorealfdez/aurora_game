#ifndef CAMERA_H
#define CAMERA_H

#include "Vector2.h"

class Camera {
    private:
        Vector2 position;
        Vector2 size;
        float zoom;
        float smoothFactor;
    public:
        void setPosition(float x, float y);
        const Vector2& getPosition();
        void setSize(float width, float height);
        Vector2 getSize();
        void setZoom(float newZoom);
        float getZoom();
        void setSmooth(float smooth);
        
        void move(float dx, float dy);
        void update(float dt, Vector2 target);
};

#endif /* CAMERA_H */