#ifndef ENGINE2D_H
#define ENGINE2D_H

#include "GraphicEngine.h"
#include "SFMLGraphicEngine.h"
#include "Camera.h"
#include "ResourcePack.h"

using namespace std;

class Engine2D {
    private:
        GraphicEngine* graphics;
        Camera camera;
        ResourcePack resources;

    public:
        Engine2D();
        ~Engine2D();

        GraphicEngine& getGraphicEngine();
        Camera& getCamera();
        bool isOpen();
        void pollEvent();

        void loadTexture(const string& id, const string& path);
        Texture* getTexture(const string& id);

        void beginFrame();
        void endFrame();
        void drawText(const string& text, float x, float y, unsigned size);
        void drawSprite(const MySprite& mySprite);
};

#endif /* ENGINE2D_H */