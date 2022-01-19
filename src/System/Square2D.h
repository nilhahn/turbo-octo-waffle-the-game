#ifndef TURBO_OCTO_WAFFLE_THE_GAME_SQUARE2D_H
#define TURBO_OCTO_WAFFLE_THE_GAME_SQUARE2D_H

#include "Vector2D.h"

class Square2D {
public:
    explicit Square2D();
    Square2D(Vector2D& corner, float width, float height);

    float getCornerX();
    float getCornerY();

    void setCorner(Vector2D& corner);
    void setCornerX(float cornerX);
    void setCornerY(float cornerY);

    float getLowerCornerX();
    float getLowerCornerY();

    float getWidth();
    float getHeight();

    float area(); // i don't think that this one will be used in the near future

    void setWidth(float width);
    void setHeight(float height);

    // checks if a given coordinate is in this square
    bool isIn(Vector2D& coord);

    Square2D& operator=(Square2D const&);

    bool operator<(const Square2D& square) const;
    bool operator()(const Square2D& squareA, const Square2D& squareB);

private:
    Vector2D corner; // the upper left corner of this square
    float width; //  width of this square
    float height; // height of this square
};


#endif //TURBO_OCTO_WAFFLE_THE_GAME_SQUARE2D_H
