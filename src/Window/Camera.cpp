#include "Camera.h"

#include <iostream>

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

int Camera::getWidth() const {
    return this->width;
}

int Camera::getHeight() const {
    return this->height;
}

Vector2D const* Camera::getCenter() {
    return &this->center;
}

const Vector2D* Camera::getCoord() const {
    return &this->coord;
}

/**
 * Determine if a object is within the bounding rect of the camera
 * param: &position - reference to the upper left corner if the object
 * param: objWidth - the width if the object
 * param: objHeight - the height of the object
 */
bool Camera::isObjectVisible(Vector2D &position, float objWidth, float objHeight) const{
    float lowerRightCameraCornerX = (this->coord.getX() + static_cast<float>(this->width));
    float lowerRightCameraCornerY = (this->coord.getY() + static_cast<float>(this->height));
    float lowerRightObjectCornerX = (position.getX() + objWidth);
    float lowerRightObjectCornerY = (position.getY() + objHeight);

    return (position.getX() >= this->getCoord()->getX() && position.getY() >= this->getCoord()->getY() &&
    position.getX() <= lowerRightCameraCornerX && position.getY() <= lowerRightCameraCornerY ||
    (lowerRightObjectCornerX >= this->getCoord()->getX() && lowerRightObjectCornerY >= this->getCoord()->getY() &&
    lowerRightObjectCornerX <= lowerRightCameraCornerX && lowerRightObjectCornerY <= lowerRightCameraCornerY));
}
