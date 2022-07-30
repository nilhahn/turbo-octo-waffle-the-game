#ifndef TURBO_OCTO_WAFFLE_THE_GAME_SQUARE2D_H
#define TURBO_OCTO_WAFFLE_THE_GAME_SQUARE2D_H

#include "Vector2D.h"

class Square2D {
public:
    explicit Square2D();

    Square2D(Vector2Df &corner, float width, float height);

    Square2D(float x, float y, float w, float h);

    Vector2Df &getCornerSquare() const;

    Vector2Df getCenter();

    float getCornerX();

    float getCornerY();

    float getCornerX() const;

    float getCornerY() const;

    void setCorner(Vector2Df &corner);

    void move(Vector2Df &delta);

    void setCornerX(float cornerX);

    void setCornerY(float cornerY);

    float getLowerCornerX() const;

    float getLowerCornerY() const;

    float getWidth();

    float getHeight();

    float area(); // i don't think that this one will be used in the near future

    void setWidth(float width);

    void setHeight(float height);

    // checks if a given coordinate is in this square
    bool isIn(const Vector2Df &coord) const;

    Square2D &operator=(Square2D const &);

    bool operator<(const Square2D &square) const;

    bool operator>(const Square2D &square) const;

    bool operator==(const Square2D &square) const;

    bool operator()(const Square2D &squareA, const Square2D &squareB);

    void positionAt(Vector2Df &position);

    static int count;

private:

    Vector2Df corner;   // the upper left corner of this square
    float width;        // width of this square
    float height;       // height of this square
};

#endif //TURBO_OCTO_WAFFLE_THE_GAME_SQUARE2D_H
