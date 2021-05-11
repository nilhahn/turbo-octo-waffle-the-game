//
// Created by mheisler on 07.05.21.
//

#include "Camera.h"

Camera::Camera() {
}

void Camera::init(int width, int height, Vector2D& initalPosition) {
    this->width = width;
    this->height = height;
    this->coord = initalPosition;

    this->center.setX(this->coord.getX() + (this->width/2.));
    this->center.setY(this->coord.getY() + (this->height/2.));
}

void Camera::move(Vector2D& delta) {
    this->coord += delta;
}

int Camera::getWidth() {
    return this->width;
}

int Camera::getHeight() {
    return this->height;
}

Vector2D const* Camera::getCenter() {
    return &this->center;
}

const Vector2D* Camera::getCoord() {
    return &this->coord;
}