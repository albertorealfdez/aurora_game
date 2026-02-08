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

void Camera::move(float dx, float dy) {

}