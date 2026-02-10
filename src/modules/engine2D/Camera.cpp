#include "Camera.h"

void Camera::setPosition(float x, float y) {
    position = {x, y};
}

const Vector2& Camera::getPosition() {
    return position;
}

void Camera::setSize(float width, float height) {
    size = {width, height};
}

Vector2 Camera::getSize() {
    return size;
}

void Camera::setZoom(float newZoom) {
    zoom = newZoom;
}

float Camera::getZoom() {
    return zoom;
}

void Camera::setSmooth(float smooth) {
    smoothFactor = smooth;
}

void Camera::move(float dx, float dy) {

}

void Camera::update(float dt, Vector2 target) {
    Vector2 currentPosition = getPosition();
    Vector2 newPosition;
    newPosition.x = currentPosition.x + (target.x - currentPosition.x) * smoothFactor * dt;
    newPosition.y = currentPosition.y + (target.y - currentPosition.y) * smoothFactor * dt;
    setPosition(newPosition.x, newPosition.y);
}
