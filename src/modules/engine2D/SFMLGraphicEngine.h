#ifndef SFMLGRAPHICENGINE_H
#define SFMLGRAPHICENGINE_H

#include "GraphicEngine.h"
#include <SFML/Graphics.hpp>

class SFMLGraphicEngine: public GraphicEngine {
    private:
        sf::RenderWindow window;

    public:
        SFMLGraphicEngine();

        bool isOpen();
        void clear();
        void display();
};

#endif /* SFMLGRAPHICENGINE_H */