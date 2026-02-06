#include "Animator.h"

Animator::Animator() {
    currentAnimation = nullptr;
    playing = true;
    currentFrame = 0;
    timer = 0.f;

}

void Animator::applyFrame(MySprite& sprite) {
    if (currentAnimation) {
        int frame = currentAnimation->frames[currentFrame];
        int fx = (frame % currentAnimation->columns) * currentAnimation->frameWidth;
        int fy = (frame / currentAnimation->columns) * currentAnimation->frameHeight;
        
        sprite.setTextureRect(fx, fy, currentAnimation->frameWidth, currentAnimation->frameHeight);
    }
}

void Animator::addAnimation(string name, Animation animation) {
    animations[name] = animation;
}

void Animator::play(string name) {
    
    if (animations.count(name) && currentAnimation != &animations[name]) {
        currentAnimation = &animations[name];
        currentFrame = 0;
        timer = 0.f;
        playing = true;
    }
}

void Animator::stop() {
    playing = false;
    currentFrame = 0;
    timer = 0.f;
}

void Animator::update(float dt) {
    if (playing) {
        if (currentAnimation) {
            timer += dt;

            if (timer >= currentAnimation->duration) {
                timer -= currentAnimation->duration;
                currentFrame++;

                if (currentFrame >= currentAnimation->frames.size()) {
                    if (currentAnimation->loop) {
                        currentFrame = 0;
                    } else {
                        currentFrame--;
                    }
                }
            }
        }
    }
}