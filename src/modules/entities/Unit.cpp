#include "Unit.h"

Unit::Unit(Vector2 initialPosition) {
    position.current = initialPosition;
    position.last = position.current;
    speed = 180.f;
    mySprite = MySprite();
    animator = new Animator();
}

MySprite& Unit::getMySprite() {
    return mySprite;
}

Vector2 Unit::getCurrentPosition() {
    return position.current;
}

float Unit::getSpeed() {
    return speed;
}

void Unit::setSpeed(float speed) {
    this->speed = speed;
}

void Unit::setState(UnitState newState) {
    state = newState;
}