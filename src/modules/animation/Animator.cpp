#include "Animator.h"
#include <iostream>

Animator::Animator(MySprite& sprite): sprite(sprite) {
    currentAnimation = nullptr;
}

void Animator::applyFrame() {
    int row = currentAnimation->row;
    int col = currentAnimation->frames[currentFrame];

    sprite.setFrame(row, col);
}

void Animator::addAnimation(string name, Animation animation) {
    animations[name] = animation;
}

void Animator::play(string name) {
    if (currentAnimation && currentAnimation->name == name) {
        return;
    }

    if (animations.count(name)) {
        cout<<"Animator play"<<endl;
        currentAnimation = &animations[name];
        currentFrame = 0;
        timer = 0.f;

        applyFrame();
    }
}

void Animator::update() {
    if (currentAnimation) {
        timer++;

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
        applyFrame();
    }
}