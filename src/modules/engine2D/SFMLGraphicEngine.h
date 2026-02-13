#ifndef SFMLGRAPHICENGINE_H
#define SFMLGRAPHICENGINE_H

#include <SFML/Graphics.hpp>
#include "tinyxml2.h"
#include "GraphicEngine.h"

using namespace std;

class SFMLGraphicEngine: public GraphicEngine {
    private:
        sf::RenderWindow* window;
        sf::View view;

    public:
        SFMLGraphicEngine();
        ~SFMLGraphicEngine();

        bool isOpen() override;
        bool pollEvent(Event& event) override;
        void clear() override;
        void display() override;
        void setCamera(Camera& camera) override;

        void drawText(const MyText& myText) override;
        void drawSprite(const MySprite& mySprite) override;
};

#endif /* SFMLGRAPHICENGINE_H */