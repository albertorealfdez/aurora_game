#ifndef ANIMATOR_H
#define ANIMATOR_H

#include <unordered_map>        
#include "Animation.h"
#include "MySprite.h"

using namespace std;

class Animator {
    private:
        MySprite& sprite;
        unordered_map<string, Animation> animations;
        Animation* currentAnimation;
        int currentFrame;
        float timer;
        bool playing;

    public:
        Animator(MySprite& sprite);
        void addAnimation(string name, Animation animation);
        void play(string name);
        void stop();
        void update(float dt);
        void applyFrame();
};

#endif /* ANIMATOR_H */