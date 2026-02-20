#include <cmath>
#include "Player.h"

Player::Player() {
    position.current = {1280/2.f, 720/2.f};  // TODO: move to config?
    position.last = position.current;
    speed = 180.f;
    mySprite = MySprite();
    animator = new Animator();
}

void Player::init(Engine2D* engine2D) {
    animator->setTextureGetter(
        [engine2D](const std::string& id) {
            return engine2D->getTexture(id);
        }
    );

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

MySprite& Player::getMySprite() {
    return mySprite;
}

Vector2 Player::getCurrentPosition() {
    return position.current;
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

// TODO: change to set real diagonal movement
void Player::handleInput(InputManager& inputManager) {
    // Pressed key states
    if (inputManager.isKeyPressed(Key::D)) {
        setState(PlayerState::WalkRight);
    }
    if (inputManager.isKeyPressed(Key::A)) {
        setState(PlayerState::WalkLeft);
    }
    if (inputManager.isKeyPressed(Key::W)) {
        setState(PlayerState::WalkUp);
    }
    if (inputManager.isKeyPressed(Key::S)) {
        setState(PlayerState::WalkDown);
    }

    // Released key states
    if (inputManager.isKeyReleased(Key::D) || inputManager.isKeyReleased(Key::A)) {
        setState(PlayerState::Idle);
    }
    if (inputManager.isKeyReleased(Key::W) || inputManager.isKeyReleased(Key::S)) {
        setState(PlayerState::Idle);
    }

}

Vector2 Player::getNextPosition() {
    return {
        position.current.x + dx,
        position.current.y + dy
    };
}

void Player::applyMovement() {
    position.last =  position.current;
    position.current.x += dx;
    position.current.y += dy;
}

void Player::update(float dt) {
    dx = 0.f;
    dy = 0.f;

    switch (state) {
        case PlayerState::Idle:
            animator->pause();
            break;
        
        case PlayerState::WalkRight:
            animator->play("player_walk");
            dx += 1.f;
            mySprite.setScale(1.f, 1.f);
            break;

        case PlayerState::WalkLeft:
            animator->play("player_walk");
            dx -= 1.f;
            mySprite.setScale(-1.f, 1.f);
            break;

        case PlayerState::WalkUp:
            animator->play("player_walk");
            dy -= 1.f;
            mySprite.setScale(1.f, 1.f);
            break;

        case PlayerState::WalkDown:
            animator->play("player_walk");
            dy += 1.f;
            mySprite.setScale(1.f, 1.f);
            break;
        default:
            break;
    }

    float length = sqrt(dx*dx + dy*dy);

    if (length > 0) {
        dx = (dx / length) * speed * dt;
        dy = (dy / length) * speed * dt;
    }
    
    animator->update(dt);
}

void Player::render(Engine2D* engine2D, float alpha) {
    Vector2 interpolated = position.interpolate(alpha);
     
    mySprite.setPosition(interpolated.x, interpolated.y);
    animator->applyFrame(mySprite);

    engine2D->drawSprite(getMySprite());
}