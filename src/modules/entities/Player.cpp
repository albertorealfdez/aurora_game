#include "Player.h"

Player::Player(): speed(100.0f) {
    position.set(200.f, 200.f);
}

void Player::init() {
    mySprite.setTexture("assets/sprites/sprites.png");
    mySprite.setTextureRect(0, 0, 48, 48);
    mySprite.setScale(1.0f, 1.0f);
    mySprite.setPosition(100, 200);
}

MySprite& Player::getMySprite() {
    return mySprite;
}

float Player::getSpeed() {
    return speed;
}

void Player::setSpeed(float speed) {
    this->speed = speed;
}