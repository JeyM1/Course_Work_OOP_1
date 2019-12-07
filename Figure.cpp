#include "Figure.h"

Figure::Figure() : Point(), m_square(0) {}
Figure::Figure(double square) : m_square(square) {}
Figure::Figure(int x, int y, double square) : Point(x, y), m_square(square) {}
Figure::Figure(int x, int y) : Point(x, y), m_square(0) {}
Figure::Figure(FigureName::e_FigureNames name) : FigureName(name), m_square(0) {}
Figure::Figure(int x, int y, FigureName::e_FigureNames names) : Point(x, y), FigureName(names), m_square(0) {}

double Figure::getSquare() const { return m_square; }
void Figure::setSquare(double mSquare) { m_square = mSquare; }

std::ostream &operator<<(std::ostream& out, const Figure& obj) {
    out << obj.x << " " << obj.y << " " << obj.name() << " " << obj.m_square;
    return out;
}


