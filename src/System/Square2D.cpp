//
// Created by mheisler on 13.05.21.
//

#include "Square2D.h"

Square2D::Square2D(): corner(0,0), width(0), height(0) {}

Square2D::Square2D(Vector2D& corner_, float width_, float height_): corner(corner_.getX(),corner_.getY()), width(width_), height(height_){}

float Square2D::getCornerX(){
    return this->corner.getX();
}

float Square2D::getCornerY(){
    return this->corner.getY();
}

void Square2D::setCorner(Vector2D& corner){
    this->setCornerX(corner.getX());
    this->setCornerY(corner.getY());
}

void Square2D::setCornerX(float cornerX){
    this->corner.setX(cornerX);
}

void Square2D::setCornerY(float cornerY){
    this->corner.setY(cornerY);
}

float Square2D::getLowerCornerX(){
    return this->getCornerX() + width;
}

float Square2D::getLowerCornerY(){
    return this->getCornerY() + height;
}

float Square2D::area() {
    return this->height * this->width;
}

float Square2D::getWidth(){
    return this->width;
}

float Square2D::getHeight(){
    return this->height;
}

void Square2D::setWidth(float width){
    this->width = width;
}

void Square2D::setHeight(float height){
    this->height = height;
}

Square2D& Square2D::operator=(Square2D& origin) {
    this->corner = origin.corner;
    this->width = origin.width;
    this->height = origin.height;
}

bool Square2D::isIn(Vector2D& coord){
    return coord.getX() >= corner.getX() && coord.getY() >= corner.getY() &&
    coord.getX() < getLowerCornerX() && coord.getY() < getLowerCornerY();
}