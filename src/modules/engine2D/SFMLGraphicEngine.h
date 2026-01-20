#ifndef SFMLGRAPHICENGINE_H
#define SFMLGRAPHICENGINE_H

#include "GraphicEngine.h"
#include <SFML/Graphics.hpp>
using namespace std;

class SFMLGraphicEngine: public GraphicEngine {
    private:
        sf::RenderWindow* window;
        sf::Font font;

    public:
        SFMLGraphicEngine();
        ~SFMLGraphicEngine();

        bool isOpen();
        bool pollEvent(sf::Event& event);
        void clear();
        void display();

        void drawText(const string& text, float x, float y, unsigned size);
};

#endif /* SFMLGRAPHICENGINE_H */