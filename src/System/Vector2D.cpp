#include "Vector2D.h"

float Vector::length(Vector2Df &vector) {
    return std::sqrt(vector.getX() * vector.getX() + vector.getY() * vector.getY());
}

float Vector::length(Vector2Di &vector) {
    return std::sqrt(
            static_cast<float>(vector.getX() * vector.getX()) +
            static_cast<float>(vector.getY() * vector.getY()));
}

void Vector::norm(Vector2Df &vector) {
    float x = (vector.getX() < 0.f ? -0.015f : 0.015f) * vector.getX() / vector.getX();
    float y = (vector.getY() < 0.f ? -0.015f : 0.015f) * vector.getY() / vector.getY();
    vector.setX(x);
    vector.setY(y);
    // std::cout << length(vector) << std::endl;
}

float Vector::absDistance(Vector2Df &vectorA, Vector2Df &vectorB) {
    Vector2Df vector(vectorA.getX() - vectorB.getX(), vectorA.getY() - vectorB.getY());
    float dist = Vector::length(vector);
    return dist < 0 ? dist * -1.f : dist;
}
