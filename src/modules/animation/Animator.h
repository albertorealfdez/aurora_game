#ifndef ANIMATOR_H
#define ANIMATOR_H

#include <unordered_map>        
#include "Animation.h"
#include "MySprite.h"
#include "Texture.h"
#include "ResourceManager.h"

using namespace std;

class Animator {
    private:
        ResourceManager<Texture>& textureManager;

        unordered_map<string, Animation> animations;
        Animation* currentAnimation;
        int currentFrame;
        float timer;
        bool playing;
        bool paused;

    public:
        Animator(ResourceManager<Texture>& tm);
        void addAnimation(string name, Animation animation);
        void play(string name);
        void pause();
        void stop();
        void update(float dt);
        void applyFrame(MySprite& sprite);
};

#endif /* ANIMATOR_H */