//
// Created by matze on 22.05.20.
//

#include "Vector2D.h"

#include <cmath>
#include <iostream>

Vector2D::Vector2D(): x(0), y(0) {}

Vector2D::Vector2D(float x, float y): x(x), y(y) {}

float Vector2D::length() {
    return std::sqrt(x*x + y*y);
}

Vector2D Vector2D::operator*(float scalar) {
    return Vector2D(this->x * scalar, this->y * scalar);
}

Vector2D Vector2D::operator+(Vector2D &vector) {
    return Vector2D(this->x + vector.x, this->y + vector.y);
}

Vector2D &Vector2D::operator=(Vector2D vector) {
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


float Vector2D::getX() {
    return this->x;
}

float Vector2D::getY() {
    return this->y;
}

Vector2D Vector2D::operator-(Vector2D &vector) {
    return Vector2D(this->x - vector.x, this->y - vector.y);
}

float Vector2D::absDistance(Vector2D& vector) {
    float dist = Vector2D(this->x - vector.x, this->y - vector.y).length();
    return dist < 0 ? dist*-1.f : dist;
}

void Vector2D::norm() {
    this->x = (this->x < 0.f?  -0.015f : 0.015f) * this->x / this->x;
    this->y = (this->y < 0.f?  -0.015f : 0.015f) * this->y / this->y;
    std::cout << this->length() << std::endl;
}
