#include "Player.h"

Player::Player(TextureManager& tm) {
    position.current = {200.f, 100.f}; 
    position.last = position.current;
    speed = 180.f;
    mySprite = MySprite();
    animator = new Animator(tm);
}

void Player::init() {
    Animation walkRight;
    walkRight.textureName = "player_walk";
    walkRight.frames = {0, 1, 2, 3},
    walkRight.columns = 4;
    walkRight.frameWidth = 64;
    walkRight.frameHeight = 64;  

    animator->addAnimation("player_walk", walkRight);
    animator->play("player_walk");
    setState(PlayerState::Idle);
}

void Player::handleInput(InputManager& inputManager) {
    // Pressed key states
    if (inputManager.isKeyPressed(Key::D)) {
        setState(PlayerState::WalkRight);
    }
    if (inputManager.isKeyPressed(Key::A)) {
        setState(PlayerState::WalkLeft);
    }

    // Released key states
    if (inputManager.isKeyReleased(Key::D) || inputManager.isKeyReleased(Key::A)) {
        setState(PlayerState::Idle);
    }

}

void Player::update(float dt) {
    position.last =  position.current;

    switch (state) {
        case PlayerState::Idle:
            animator->pause();
            break;
        
        case PlayerState::WalkRight:
            animator->play("player_walk");
            position.current.x += speed * dt;
            mySprite.setScale(1.f, 1.f);
            mySprite.setOrigin(0.f, 0.f);
            break;

        case PlayerState::WalkLeft:
            animator->play("player_walk");
            position.current.x -= speed * dt;
            mySprite.setScale(-1.f, 1.f);
            mySprite.setOrigin(64.f, 0.f);
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