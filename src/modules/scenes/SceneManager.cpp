#include "SceneManager.h"

SceneManager::SceneManager() {
    currentScene = nullptr;
}

SceneManager::~SceneManager() {
    delete currentScene;
    delete pendingScene;
}

Scene* SceneManager::getCurrentScene() const {
    return currentScene;
}

void SceneManager::changeScene(Scene* scene) {
    pendingScene = scene;
}

void SceneManager::processPending() {
    if (pendingScene) {
        delete currentScene;
        currentScene = pendingScene;
        pendingScene = nullptr;
    }
}