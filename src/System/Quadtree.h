#ifndef QUADTREE_QUADTREE_H
#define QUADTREE_QUADTREE_H

#include <iostream>

#include "Square2D.h"

template<typename V>
class Quadtree {
public:
    typedef enum {
        NW = 0, NE, SE, SW
    } Quadrant;

    Quadtree(Square2D &coord, V &v, Quadtree *root);

    Quadtree(Square2D &coord, V &v);

    ~Quadtree();

    void insert(Square2D &coord, V &v);

    void remove(Square2D &coord);

    bool contains(Square2D &coord);

    V *find(Square2D const &coord);

    bool isRoot();

    bool hasChildren();

    int size();

protected:
    static constexpr int NODES = 4;

    Square2D own;

    Quadtree *root;
    Quadtree *children[NODES];

    int fill{};
    V value;

    Quadrant getQuadrant(Vector2Df &key);

    void initChildren();
};

template<typename V>
Quadtree<V>::Quadtree(Square2D &coord, V &value, Quadtree *root) {
    this->root = root;

    this->own = coord;

    this->value = value;
    this->initChildren();
}

template<typename V>
Quadtree<V>::Quadtree(Square2D &coord, V &value) {
    this->root = nullptr;

    this->own = coord;

    this->value = value;
    this->initChildren();
}

template<typename V>
Quadtree<V>::~Quadtree() {
    for (int index = 0; index < NODES; index++) {
        if (nullptr != children[index]) {
            delete children[index];
        }
        children[index] = nullptr;
    }
}

template<typename V>
void Quadtree<V>::insert(Square2D &coord, V &v) {
    Quadrant quadrant = this->getQuadrant(coord.getCornerSquare());

    if (coord.isIn(this->own.getCornerSquare())) {
        return;
    }

    if (children[quadrant] == nullptr) {
        children[quadrant] = new Quadtree(coord, v, this);
        this->fill++;
    } else {
        children[quadrant]->insert(coord, v);
    }
}

template<typename V>
bool Quadtree<V>::contains(Square2D &coord) {
    if (this->own.isIn(coord.getCornerSquare())) {
        return true;
    }

    for (auto &child: this->children) {
        if (child != nullptr && child->contains(coord)) {
            return true;
        }
    }

    return false;
}

template<typename V>
V *Quadtree<V>::find(Square2D const &coord) {
    if (this->own.isIn(coord.getCornerSquare())) {
        return &this->value;
    }

    for (auto &child: this->children) {
        if (child != nullptr) {
            auto element = child->find(coord);
            if (element != nullptr) {
                return element;
            }
        }
    }

    return nullptr;
}

template<typename V>
void Quadtree<V>::remove(Square2D &coord) {
    Quadtree *temp[NODES] = {nullptr, nullptr, nullptr, nullptr};

    for (int index = 0; index < NODES; index++) {
        if (this->children[index] != nullptr) {
            if (this->children[index]->own == coord) {
                if (this->children[index]->hasChildren()) {
                    for (int inner = 0; inner < NODES; inner++) {
                        temp[inner] = this->children[index]->children[inner];
                        this->children[index]->children[inner] = nullptr;
                    }
                }

                delete this->children[index];
                this->children[index] = nullptr;

                for (auto &child: temp) {
                    if (child != nullptr) {
                        if (this->isRoot() == false) {
                            this->root->insert(child->own, child->value);
                        } else {
                            this->insert(child->own, child->value);
                        }
                        delete child;
                    }
                }

                this->fill--;
                return;
            }
            this->children[index]->remove(coord);
        }
    }
}

template<typename V>
bool Quadtree<V>::isRoot() {
    return this->root == nullptr;
}

template<typename V>
bool Quadtree<V>::hasChildren() {
    return this->fill != 0;
}

template<typename V>
int Quadtree<V>::size() {
    int cnt = 0;
    for (auto &child: children) {
        if (child != nullptr) {
            cnt += child->size();
        }
    }
    return ++cnt;
}

template<typename V>
void Quadtree<V>::initChildren() {
    this->fill = 0;
    for (auto &child: children) {
        child = nullptr;
    }
}

template<typename V>
typename Quadtree<V>::Quadrant Quadtree<V>::getQuadrant(Vector2Df &key) {
    Quadrant quadrant;

    if (key.getY() >= this->own.getCornerY()) {
        if (key.getX() < this->own.getCornerX()) {
            quadrant = NW;
        } else {
            quadrant = NE;
        }
    } else {
        if (key.getX() < this->own.getCornerX()) {
            quadrant = SW;
        } else {
            quadrant = SE;
        }
    }

    return quadrant;
}

#endif //QUADTREE_QUADTREE_H
