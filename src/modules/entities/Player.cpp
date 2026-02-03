#include "Player.h"

#include <iostream>
Player::Player(): speed(0.05f) {
    x = 200.f;
    y = 100.f;

    position.set(x, y);
}

void Player::init() {
    mySprite.setTexture("assets/sprites/walk.png");
    mySprite.setTextureRect(0, 0, 64, 64);
    mySprite.setScale(1.0f, 1.0f);
    mySprite.setPosition(x, y);
    mySprite.setFrameHeight(64);
    mySprite.setFrameWidth(64);

    animator = new Animator(mySprite);

    Animation walkRight = {
        "walkRight",
        {0, 1, 2, 3, 4, 5, 6, 7},
        0,
        0.2f
    };

    animator->addAnimation("walkRight", walkRight);
    cout<<"Init Player"<<endl;
}

MySprite& Player::getMySprite() {
    return mySprite;
}

void Player::update() {
    switch (state) {
        case PlayerState::WalkRight:
            animator->play("walkRight");
            x += speed;
            break;
        
        default:
            break;
    }
    animator->update();
    mySprite.setPosition(x, y);
}

float Player::getSpeed() {
    return speed;
}

void Player::setSpeed(float speed) {
    this->speed = speed;
}

void Player::setState(PlayerState newState) {
    state = newState;
}