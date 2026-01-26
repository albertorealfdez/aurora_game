#ifndef GRAPHICENGINE_H
#define GRAPHICENGINE_H

#include <iostream>
#include "Event.h"
using namespace std;

class GraphicEngine {
    public:
        virtual ~GraphicEngine() = default;

        virtual bool isOpen() = 0;
        virtual bool pollEvent(Event& event) = 0;
        virtual void clear() = 0;
        virtual void display() = 0;
        virtual void drawText(const string& text, float x, float y, unsigned size) = 0;
};

#endif /* GRAPHICENGINE_H */