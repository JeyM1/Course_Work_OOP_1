#include "Rectangle.h"

Rectangle::Rectangle() : Figure(), a(0), b(0) {}
Rectangle::Rectangle(double a, double b) : Figure(FigureName::Rectangle), a(a), b(b) {
    this->m_square = a * b;
}
Rectangle::Rectangle(int x, int y, double a, double b) : Figure(x, y, FigureName::Rectangle, a*b), a(a), b(b) {}

std::ostream &operator<<(std::ostream& out, const Rectangle& obj) {
    out << obj.x << " " << obj.y << " " << obj.m_square << " " << obj.name() << " " << obj.a << " " << obj.b;
    return out;
}

Rectangle::~Rectangle() = default;


