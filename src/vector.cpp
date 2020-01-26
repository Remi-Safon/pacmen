#include "vector.h"

Vector::Vector () {}

Vector::Vector (int px, int py)
{
    this->x = px;
    this->y = py;
}


void Vector::set(int xx, int yy) {
    this->x = xx;
    this->y = yy;
}

void Vector::add(int xx, int yy) {
    this->x += xx;
    this->y += yy;
}

bool Vector::operator==(const Vector & v) const {
    return this->x == v.x && this->y == v.y;
}
