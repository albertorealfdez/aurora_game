#include <iostream>
#include "Player.h"

Player::Player(): speed(0.05f) {
    x = 200.f;
    y = 100.f;

    position.set(x, y);
}

void Player::init() {
    mySprite.setTexture("assets/sprites/warrior.png");
    mySprite.setTextureRect(0, 0, 90, 90);
    mySprite.setScale(1.0f, 1.0f);
    mySprite.setPosition(x, y);
    mySprite.setFrameHeight(90);
    mySprite.setFrameWidth(90);

    animator = new Animator(mySprite);

    Animation walkRight = {
        "walkRight",
        {0, 1, 2, 3, 4, 5, 6, 7},
        0,
        0.2f
    };

    animator->addAnimation("walkRight", walkRight);
}

MySprite& Player::getMySprite() {
    return mySprite;
}

void Player::handleInput(InputManager& inputManager) {
    // Pressed key states
    if (inputManager.isKeyPressed(Key::D)) {
        setState(PlayerState::WalkRight);
    }

    // Released key states
    if (inputManager.isKeyReleased(Key::D)) {
        cout<<"Released"<<endl;
        setState(PlayerState::Idle);
    }
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