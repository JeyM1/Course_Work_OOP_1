#include "Point.h"

Point::Point() : x(0), y(0) {}
Point::Point(int x, int y) : x(x), y(y) {}
Point::~Point() = default;
Point::Point(const Point& obj) : x(obj.x), y(obj.y) {}

int Point::getX() const { return x; }
int Point::getY() const { return y; }

void Point::setX(int x) { this->x = x; }
void Point::setY(int y) { this->y = y; }

std::ostream &operator<<(std::ostream& out, const Point& obj) {
    return out << obj.x << "_" << obj.y;
}

Point Point::operator+(const Point& obj) const {
    return Point(this->x + obj.x, this->y + obj.y);
}

Point Point::operator/(const Point& obj) const {
    return Point(this->x/obj.x, this->y / obj.y);
}

Point Point::operator/(int num) const {
    return Point(this->x / num, this->y / num);
}


