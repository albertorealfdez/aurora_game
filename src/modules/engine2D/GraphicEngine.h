#ifndef GRAPHICENGINE_H
#define GRAPHICENGINE_H

#include <iostream>
#include "Event.h"
#include "MySprite.h"
#include "MyText.h"
#include "Camera.h"

using namespace std;

class GraphicEngine {
    public:
        virtual ~GraphicEngine() = default;

        virtual bool isOpen() = 0;
        virtual bool pollEvent(Event& event) = 0;
        virtual void clear() = 0;
        virtual void display() = 0;
        virtual void setCamera(Camera& camera) = 0;
        virtual void drawText(const MyText& myText) = 0;
        virtual void drawSprite(const MySprite& mySprite) = 0;
};

#endif /* GRAPHICENGINE_H */