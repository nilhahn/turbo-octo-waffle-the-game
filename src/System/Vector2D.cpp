#include "Vector2D.h"

#include <cmath>
#include <iostream>

Vector2D::Vector2D() : x(0), y(0) {}

Vector2D::Vector2D(float x, float y) : x(x), y(y) {}

float Vector2D::length() {
    return std::sqrt(x * x + y * y);
}

Vector2D Vector2D::operator*(float scalar) {
    return {this->x * scalar, this->y * scalar};
}

Vector2D Vector2D::operator+(const Vector2D &vector) const {
    return {this->x + vector.x, this->y + vector.y};
}

Vector2D &Vector2D::operator=(Vector2D &vector) {
    this->x = vector.x;
    this->y = vector.y;
    return *this;
}

Vector2D &Vector2D::operator+=(Vector2D &vector) {
    this->x += vector.x;
    this->y += vector.y;
    return *this;
}

Vector2D &Vector2D::operator-=(Vector2D &vector) {
    this->x -= vector.x;
    this->y -= vector.y;
    return *this;
}


float Vector2D::getX() const {
    return this->x;
}

float Vector2D::getY() const {
    return this->y;
}

void Vector2D::setX(float x) {
    this->x = x;
}

void Vector2D::setY(float y) {
    this->y = y;
}

Vector2D Vector2D::operator-(const Vector2D &vector) const {
    return {this->x - vector.x, this->y - vector.y};
}

float Vector2D::absDistance(Vector2D &vector) {
    float dist = Vector2D(this->x - vector.x, this->y - vector.y).length();
    return dist < 0 ? dist * -1.f : dist;
}

void Vector2D::norm() {
    this->x = (this->x < 0.f ? -0.015f : 0.015f) * this->x / this->x;
    this->y = (this->y < 0.f ? -0.015f : 0.015f) * this->y / this->y;
    std::cout << this->length() << std::endl;
}

std::string Vector2D::toString() {
    std::string str = "(x:";
    str += this->getX();
    str += ";y:";
    str += this->getY();
    str += ")";
    return str;
}
