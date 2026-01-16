#ifndef ENGINE2D_H
#define ENGINE2D_H

#include "GraphicEngine.h"
#include "SFMLGraphicEngine.h"

using namespace std;

class Engine2D {
    private:
        GraphicEngine *graphics;

    public:
        Engine2D();
        ~Engine2D();

        bool isOpen();
        void test();
};

#endif /* ENGINE2D_H */