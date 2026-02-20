#include "Enemy.h"

Enemy::Enemy() {
    position.current = {1280/3.f, 720/2.f};  // TODO: move to config?
    position.last = position.current;
    speed = 180.f;
    mySprite = MySprite();
    animator = new Animator();
}

void Enemy::init(Engine2D* engine2D) {

}

MySprite& Enemy::getMySprite() {
    return mySprite;
}

Vector2 Enemy::getCurrentPosition() {
    return position.current;
}

float Enemy::getSpeed() {
    return speed;
}

void Enemy::setSpeed(float speed) {
    this->speed = speed;
}

void Enemy::setState(EnemyState newState) {
    state = newState;
}