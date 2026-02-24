#include <cmath>
#include "Soldier.h"

Soldier::Soldier(Vector2 initialPostion): Unit(initialPostion) {

}

void Soldier::init(Engine2D* engine2D) {
    animator->setTextureGetter(
        [engine2D](const std::string& id) {
            return engine2D->getTexture(id);
        }
    );
    cout<<"Calling Soldier init"<<endl;
    Animation walkRight;
    walkRight.textureName = "soldier_walk";
    walkRight.frames = {0, 1, 2, 3},
    walkRight.columns = 4;
    walkRight.frameWidth = 64;
    walkRight.frameHeight = 64;  

    animator->addAnimation("soldier_walk", walkRight);
    animator->play("soldier_walk");
    setState(UnitState::Idle);
}

void Soldier::update(float dt) {
    dx = 0.f;
    dy = 0.f;

    switch (state) {
        case UnitState::Idle:
            animator->pause();
            break;
        
        case UnitState::WalkRight:
            animator->play("soldier_walk");
            dx += 1.f;
            mySprite.setScale(1.f, 1.f);
            break;

        case UnitState::WalkLeft:
            animator->play("soldier_walk");
            dx -= 1.f;
            mySprite.setScale(-1.f, 1.f);
            break;

        case UnitState::WalkUp:
            animator->play("soldier_walk");
            dy -= 1.f;
            mySprite.setScale(1.f, 1.f);
            break;

        case UnitState::WalkDown:
            animator->play("soldier_walk");
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

void Soldier::render(Engine2D* engine2D, float alpha) {
    Vector2 interpolated = position.interpolate(alpha);
     
    mySprite.setPosition(interpolated.x, interpolated.y);
    animator->applyFrame(mySprite);

    engine2D->drawSprite(getMySprite());
}