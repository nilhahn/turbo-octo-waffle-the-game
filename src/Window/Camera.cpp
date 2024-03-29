#include "Camera.h"

#include <iostream>

Camera::Camera() {
}

void Camera::init(int width, int height, Vector2Df& initalPosition) {
    this->width = width;
    this->height = height;
    this->coord = initalPosition;

    this->center.setX(this->coord.getX() + (this->width/2.));
    this->center.setY(this->coord.getY() + (this->height/2.));
}

void Camera::move(Vector2Df& delta) {
    this->coord += delta;
}

int Camera::getWidth() const {
    return this->width;
}

int Camera::getHeight() const {
    return this->height;
}

Vector2Df const* Camera::getCenter() {
    return &this->center;
}

const Vector2Df* Camera::getCoord() const {
    return &this->coord;
}

/**
 * Determine if a object is within the bounding rect of the camera
 * param: &position - reference to the upper left corner if the object
 * param: objWidth - the width if the object
 * param: objHeight - the height of the object
 */
bool Camera::isObjectVisible(Vector2Df &position, float objWidth, float objHeight) const{
    float lowerRightCameraCornerX = (this->coord.getX() + static_cast<float>(this->width));
    float lowerRightCameraCornerY = (this->coord.getY() + static_cast<float>(this->height));
    float lowerRightObjectCornerX = (position.getX() + objWidth);
    float lowerRightObjectCornerY = (position.getY() + objHeight);

    return ((position.getX() >= this->getCoord()->getX() &&
    lowerRightObjectCornerX <= lowerRightCameraCornerX)  ||
    position.getY() >= this->getCoord()->getY() &&
    position.getX() <= lowerRightCameraCornerX &&
    position.getY() <= lowerRightCameraCornerY ||
    (lowerRightObjectCornerX >= this->getCoord()->getX() &&
    lowerRightObjectCornerY >= this->getCoord()->getY() &&
    lowerRightObjectCornerY <= lowerRightCameraCornerY));
}

Square2D Camera::getBoundingRect() const {
    return {const_cast<Vector2Df&>(this->coord), static_cast<float>(width), static_cast<float>(height)};
}

bool Camera::isObjectVisible(Square2D *square) const{
    return this->isObjectVisible(square->getCornerSquare(), square->getWidth(), square->getHeight());
}
