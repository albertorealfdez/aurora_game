#ifndef RECT_H
#define RECT_H

struct Rect {
    float left;
    float top;
    float width;
    float height;

    Rect() =  default;
    Rect(float l, float t, float w, float h) {
        left = l;
        top = t;
        width = w;
        height = h;
    }
};

#endif /* RECT_H */
