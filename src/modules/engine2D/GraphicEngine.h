#ifndef GRAPHICENGINE_H
#define GRAPHICENGINE_H

class GraphicEngine {
    public:
        virtual ~GraphicEngine() = default;

        virtual bool isOpen() = 0;
        virtual void clear() = 0;
        virtual void display() = 0;
};

#endif /* GRAPHICENGINE_H */