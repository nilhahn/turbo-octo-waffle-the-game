#include "Square2D.h"
#include <iostream>

int Square2D::count = 0;

Square2D::Square2D() : corner(0, 0), width(0), height(0) {}

Square2D::Square2D(float x, float y, float w, float h) : corner(x, y), width(w), height(h) {}

Square2D::Square2D(Vector2Df &corner_, float width_, float height_) : corner(corner_.getX(), corner_.getY()),
                                                                      width(width_), height(height_) {
}

float Square2D::getCornerX() {
    return this->corner.getX();
}

float Square2D::getCornerY() {
    return this->corner.getY();
}

float Square2D::getCornerX() const {
    return this->corner.getX();
}

float Square2D::getCornerY() const {
    return this->corner.getY();
}

void Square2D::setCorner(Vector2Df &corner) {
    this->setCornerX(corner.getX());
    this->setCornerY(corner.getY());
}

void Square2D::setCornerX(float cornerX) {
    this->corner.setX(cornerX);
}

void Square2D::setCornerY(float cornerY) {
    this->corner.setY(cornerY);
}

float Square2D::getLowerCornerX() const {
    return this->corner.getX() + width;
}

float Square2D::getLowerCornerY() const {
    return this->corner.getY() + height;
}

float Square2D::area() {
    return this->height * this->width;
}

float Square2D::getWidth() const {
    return this->width;
}

float Square2D::getHeight() const {
    return this->height;
}

void Square2D::setWidth(float width) {
    this->width = width;
}

void Square2D::setHeight(float height) {
    this->height = height;
}

Square2D &Square2D::operator=(Square2D const &origin) {
    this->corner.setX(origin.corner.getX());
    this->corner.setY(origin.corner.getY());
    this->width = origin.width;
    this->height = origin.height;
    return *this;
}

bool Square2D::isIn(const Vector2Df &coord) const {
    return coord.getX() >= corner.getX() && coord.getY() >= corner.getY() &&
           coord.getX() < getLowerCornerX() && coord.getY() < getLowerCornerY();
}

bool Square2D::operator<(const Square2D &square) const {
    Square2D::count++;
    return !square.isIn(this->corner);
}

bool Square2D::operator>(const Square2D &square) const {
    Square2D::count++;
    return square.isIn(this->corner);
}

bool Square2D::operator==(const Square2D &square) const {
    return this->getCornerX() == square.getCornerX() && this->getCornerY() == square.getCornerY() &&
           this->getLowerCornerX() == square.getLowerCornerX() && this->getLowerCornerY() == square.getLowerCornerY();
}

bool Square2D::operator()(const Square2D &squareA, const Square2D &squareB) {
    Square2D::count++;
    return squareA < squareB;
}

Vector2Df &Square2D::getCornerSquare() const {
    return const_cast<Vector2Df &>(this->corner);
}

Vector2Df Square2D::getCenter() {
    return {(this->getCornerX() + this->width) / 2.f, (this->getCornerY() + this->height) / 2.f};
}

void Square2D::move(Vector2Df& delta) {
    this->corner += delta;
}

void Square2D::positionAt(Vector2Df& position) {
    this->corner.setX(position.getX());
    this->corner.setY(position.getY());
}

