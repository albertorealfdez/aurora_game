#include "Player.h"

Player::Player() {
    position.current = {200.f, 100.f}; 
    position.last = position.current;
    speed = 180.f;
    mySprite = MySprite();
}

void Player::init(TextureManager& tm) {
    //mySprite.setTexture("assets/sprites/warrior-run.png");
    //mySprite.setTextureRect(0, 0, 128, 128);

    animator = new Animator(tm);

    Animation walkRight;
    walkRight.textureName = "player-walk";
    walkRight.frames = {0, 1, 2, 3, 4, 5},
    walkRight.columns = 4;
    walkRight.frameWidth = 128;
    walkRight.frameHeight = 164;  

    animator->addAnimation("playerWalk", walkRight);
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
            animator->play("playerWalk");
            position.current.x += speed * dt;
            break;

        case PlayerState::Idle:
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