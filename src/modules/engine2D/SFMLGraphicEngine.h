#ifndef SFMLGRAPHICENGINE_H
#define SFMLGRAPHICENGINE_H

#include <SFML/Graphics.hpp>
#include "GraphicEngine.h"

using namespace std;

class SFMLGraphicEngine: public GraphicEngine {
    private:
        sf::RenderWindow* window;
        sf::View view;
        sf::Font font;

    public:
        SFMLGraphicEngine();
        ~SFMLGraphicEngine();

        bool isOpen() override;
        bool pollEvent(Event& event) override;
        void clear() override;
        void display() override;
        void setCamera(Camera& camera) override;

        void drawText(const string& text, float x, float y, unsigned size) override;
        void drawSprite(const MySprite& mySprite);
};

#endif /* SFMLGRAPHICENGINE_H */