#include "Circle.h"

Circle::Circle() : Figure(FigureName::Circle), m_radius(0) {}
Circle::Circle(double radius) : Figure(FigureName::Circle), m_radius(radius) {}
Circle::Circle(int x, int y) : Figure(x, y, FigureName::Circle), m_radius(0) {}
Circle::Circle(int x, int y, double radius) : Figure(x, y, FigureName::Circle), m_radius(radius) {}
Circle::~Circle() = default;

double Circle::getRadius() const { return m_radius; }
void Circle::setRadius(double radius) { m_radius = radius; }

std::ostream &operator<<(std::ostream& out, const Circle& obj) {
    out << obj.x << " " << obj.y << " " << obj.m_square << " "  << obj.name() << " "  << obj.m_radius;
    return out;
}
