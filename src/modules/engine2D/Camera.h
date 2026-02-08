#ifndef CAMERA_H
#define CAMERA_H

#include "Vector2.h"

class Camera {
    private:
        Vector2 position;
        Vector2 size;
        float zoom;
        
    public:
        void setPosition(float x, float y);
        const Vector2& getPosition();
        void setSize(float width, float height);
        Vector2 getSize();
        void setZoom(float newZoom);
        float getZoom();
        
        void move(float dx, float dy);
};

#endif /* CAMERA_H */