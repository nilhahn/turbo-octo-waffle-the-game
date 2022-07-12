#include "Vector2Df.h"

#include <cmath>
#include <iostream>

Vector2Df::Vector2Df() {
    this->x = 0.;
    this->y = 0.;
}

float Vector2Df::length() {
    return std::sqrt(x * x + y * y);
}

Vector2Df Vector2Df::operator* (float scalar) {
    return {this->x * scalar, this->y * scalar};
}

Vector2Df Vector2Df::operator+(const Vector2Df &vector) const {
    return {this->x + vector.x, this->y + vector.y};
}

Vector2Df &Vector2Df::operator=(Vector2Df &vector) {
    this->x = vector.x;
    this->y = vector.y;
    return *this;
}

Vector2Df &Vector2Df::operator+=(Vector2Df &vector) {
    this->x += vector.x;
    this->y += vector.y;
    return *this;
}

Vector2Df &Vector2Df::operator-=(Vector2Df &vector) {
    this->x -= vector.x;
    this->y -= vector.y;
    return *this;
}


float Vector2Df::getX() const {
    return this->x;
}

float Vector2Df::getY() const {
    return this->y;
}

void Vector2Df::setX(float x) {
    this->x = x;
}

void Vector2Df::setY(float y) {
    this->y = y;
}

Vector2Df Vector2Df::operator-(const Vector2Df &vector) const {
    return {this->x - vector.x, this->y - vector.y};
}

float Vector2Df::absDistance(Vector2Df &vector) {
    float dist = Vector2Df(this->x - vector.x, this->y - vector.y).length();
    return dist < 0 ? dist * -1.f : dist;
}

void Vector2Df::norm() {
    this->x = (this->x < 0.f ? -0.015f : 0.015f) * this->x / this->x;
    this->y = (this->y < 0.f ? -0.015f : 0.015f) * this->y / this->y;
    std::cout << this->length() << std::endl;
}

std::string Vector2Df::toString() {
    std::string str = "(x:" + std::to_string(this->getX()) + ";y:" + std::to_string(this->getY()) + ")";
    return str;
}
