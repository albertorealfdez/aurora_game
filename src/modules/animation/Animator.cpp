#include "Animator.h"

Animator::Animator(MySprite& sprite): sprite(sprite) {
    currentAnimation = nullptr;
    playing = true;
    currentFrame = 0;
    timer = 0.f;

}

void Animator::applyFrame() {
    if (currentAnimation) {
        int row = currentAnimation->row;
        int col = currentAnimation->frames[currentFrame];

        sprite.setFrame(row, col);
    }
}

void Animator::addAnimation(string name, Animation animation) {
    animations[name] = animation;
}

void Animator::play(string name) {
    playing = true;
    if (currentAnimation && currentAnimation->name == name) {
        return;
    }

    if (animations.count(name)) {
        currentAnimation = &animations[name];
        currentFrame = 0;
        timer = 0.f;
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