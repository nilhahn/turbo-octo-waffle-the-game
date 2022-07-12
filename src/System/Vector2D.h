#ifndef TURBO_OCTO_WAFFLE_THE_GAME_VECTOR2D_H
#define TURBO_OCTO_WAFFLE_THE_GAME_VECTOR2D_H

#include <string>
#include <cmath>

template<typename T>
class Vector2D {
public:
    Vector2D() = default;
    Vector2D(T x, T y) : x(x), y(y) {};

    T getY() const { return y; }
    T getX() const { return x; }

    void setY(T coordY) { this->y = coordY; }
    void setX(T coordX) { this->x = coordX; }

    std::string toString();
protected:
    T x;
    T y;
};

template<typename T>
std::string Vector2D<T>::toString() {
    std::string str = "(x:" + std::to_string(this->getX()) + ";y:" + std::to_string(this->getY()) + ")";
    return str;
}

template<typename T>
Vector2D<T> operator*(Vector2D<T> &vector, T scalar) {
    return {vector.getX() * scalar, vector.getY() * scalar};
}

template<typename T>
Vector2D<T> operator+(const Vector2D<T> &vectorA, const Vector2D<T> &vectorB) {
    return {vectorA.getX() + vectorB.getX(), vectorA.getY() + vectorB.getY()};
}

template<typename T>
Vector2D<T> operator-(const Vector2D<T> &vectorA, const Vector2D<T> &vectorB) {
    return {vectorA.getX() - vectorB.getX(), vectorA.getY() - vectorB.getY()};
}

template<typename T>
bool operator==(const Vector2D<T> &vectorA, const Vector2D<T> &vectorB) {
    return vectorA.getX() == vectorB.getX() && vectorA.getY() == vectorB.getY();
}

template<typename T>
Vector2D<T> &operator+=(Vector2D<T> &vectorA, Vector2D<T> &vectorB) {
    vectorA.setX(vectorA.getX() + vectorB.getX());
    vectorA.setY(vectorA.getY() + vectorB.getY());
    return vectorA;
}

template<typename T>
Vector2D<T> &operator-=(Vector2D<T> &vectorA, Vector2D<T> &vectorB) {
    vectorA.setX(vectorA.getX() - vectorB.getX());
    vectorA.setY(vectorA.getY() - vectorB.getY());
    return vectorA;
}

typedef Vector2D<float> Vector2Df;
typedef Vector2D<int> Vector2Di;

class Vector {
public:
    Vector() = delete;
    static float length(Vector2Df &vector);
    static float length(Vector2Di &vector);
    static void norm(Vector2Df &vector);
    static float absDistance(Vector2Df &vectorA, Vector2Df &vectorB);
};

#endif //TURBO_OCTO_WAFFLE_THE_GAME_VECTOR2D_H
