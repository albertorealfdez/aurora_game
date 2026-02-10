#ifndef ANIMATOR_H
#define ANIMATOR_H

#include <unordered_map>
#include <functional>
#include "Animation.h"
#include "MySprite.h"
#include "Texture.h"

using namespace std;

class Animator {
    using TextureGetter = function<Texture*(const std::string&)>;
    
    private:
        TextureGetter textureGetter;
        unordered_map<string, Animation> animations;
        Animation* currentAnimation;
        int currentFrame;
        float timer;
        bool playing;
        bool paused;

    public:
        Animator();
        void setTextureGetter(TextureGetter getter);
        
        void addAnimation(string name, Animation animation);
        void play(string name);
        void pause();
        void stop();
        void update(float dt);
        void applyFrame(MySprite& sprite);
};

#endif /* ANIMATOR_H */