#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "Scene.h"

using namespace std;

class SceneManager {
    private:
        Scene* currentScene;
        Scene* pendingScene;

    public: 
        SceneManager();
        ~SceneManager();

        Scene* getCurrentScene() const;
        void changeScene(Scene* scene);
        void processPending();
};

#endif /* SCENE_MANAGER_H */