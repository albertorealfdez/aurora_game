#ifndef SCENE_H
#define SCENE_H

#include "InputManager.h"
#include "Engine2D.h"

class Scene {
    public:
        virtual ~Scene() = default;

        virtual void init(Engine2D* engine2D) = 0;
        virtual void handleInput(InputManager& inputManager) = 0;
        virtual void update(float dt) = 0;
        virtual void render(Engine2D* engine2D, float alpha) = 0;
        virtual Vector2 getCameraTarget() const = 0;
};

#endif /* SCENE_H */