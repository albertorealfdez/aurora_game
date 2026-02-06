#include "Player.h"

Player::Player() {
    position.current = {200.f, 100.f}; 
    position.last = position.current;
    speed = 180.f;
    mySprite = MySprite();
}

void Player::init() {
    mySprite.setTexture("assets/sprites/warrior-run.png");
    mySprite.setTextureRect(0, 0, 128, 128);
    //mySprite.setScale(1.0f, 1.0f);
    //mySprite.setPosition(position.current.x, position.current.y);
    //mySprite.setFrameHeight(128);
    //mySprite.setFrameWidth(128);

    animator = new Animator();

    Animation walkRight;
    walkRight.textureName = "walk-right";
    walkRight.frames = {0, 1, 2, 3, 4, 5},
    walkRight.columns = 1;
    walkRight.frameWidth = 100;
    walkRight.frameHeight = 100;  

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
    animator->applyFrame(mySprite);

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