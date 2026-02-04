#include "Player.h"

Player::Player() {
    x = 200.f;
    y = 100.f;
    speed = 180.f;

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
        0.1f
    };

    animator->addAnimation("walkRight", walkRight);
}

void Player::handleInput(InputManager& inputManager) {
    // Pressed key states
    if (inputManager.isKeyPressed(Key::D)) {
        setState(PlayerState::WalkRight);
    }

    // Released key states
    if (inputManager.isKeyReleased(Key::D)) {
        setState(PlayerState::Idle);
    }
}

void Player::update(float dt) {
    position.last =  position.current;

    switch (state) {
        case PlayerState::WalkRight:
            animator->play("walkRight");
            position.current.x += speed * dt;
            break;

        case PlayerState::Idle:
            //animator->play("walkRight");
            animator->stop();
            break;
        
        default:
            break;
    }
    animator->update(dt);
}

void Player::render(Engine2D* engine2D, float alpha) {
    Vector2 interpolated = position.interpolate(alpha);
    mySprite.setPosition(interpolated.x, interpolated.y);
    animator->applyFrame();

    engine2D->drawSprite(getMySprite());
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

void Player::setState(PlayerState newState) {
    state = newState;
}