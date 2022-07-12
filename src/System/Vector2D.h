#ifndef TURBO_OCTO_WAFFLE_THE_GAME_VECTOR2D_H
#define TURBO_OCTO_WAFFLE_THE_GAME_VECTOR2D_H

template<typename T>
class Vector2D {
public:
    Vector2D() {};

    Vector2D(T x, T y) : x(x), y(y) {};

    virtual T length() = 0;

    T getY() const {
        return y;
    }

    T getX() const {
        return x;
    }

    void setY(T& coordY) {
        this->y = coordY;
    }

    void setX(T& coordX) {
        this->x = coordX;
    }

    virtual Vector2D<T> operator*(T scalar) = 0;
    virtual Vector2D<T> operator+(const Vector2D<T> &vector) const = 0;
    virtual Vector2D<T> operator-(const Vector2D<T> &vector) const = 0;
    virtual Vector2D<T> &operator=(Vector2D<T> &vector) = 0;
    virtual Vector2D<T> &operator+=(Vector2D<T> &vector) = 0;
    virtual Vector2D<T> &operator-=(Vector2D<T> &vector) = 0;

    virtual T absDistance(Vector2D<T> &vector2D) = 0;

    virtual void norm() = 0;
    virtual std::string toString() = 0;

protected:
    T x;
    T y;
};


#endif //TURBO_OCTO_WAFFLE_THE_GAME_VECTOR2D_H
