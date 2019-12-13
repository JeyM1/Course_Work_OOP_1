#include "Figure.h"

Figure::Figure() : Point(), m_square(0) {}
Figure::Figure(double square) : Point(), m_square(square) {}
Figure::Figure(int x, int y, double square) : Point(x, y), m_square(square) {}
Figure::Figure(int x, int y) : Point(x, y), m_square(0) {}
Figure::Figure(FigureName::e_FigureNames name) : Point(), FigureName(name), m_square(0) {}
Figure::Figure(int x, int y, FigureName::e_FigureNames name) : Point(x, y), FigureName(name), m_square(0) {}
Figure::Figure(const Point& point, FigureName::e_FigureNames name) : Point(point), FigureName(name), m_square(0) {}
Figure::Figure(const Figure& obj) : Point(obj.x, obj.y), FigureName(obj.m_figure_name), m_square(obj.m_square) {}
Figure::Figure(int x, int y, FigureName::e_FigureNames name, double square) : Point(x, y), FigureName(name),
                                                                              m_square(square) {}
Figure::Figure(FigureName::e_FigureNames name, double square) : FigureName(name), m_square(square) {}
Figure::~Figure() = default;

double Figure::getSquare() const { return m_square; }
void Figure::setSquare(double mSquare) { m_square = mSquare; }

std::ostream &operator<<(std::ostream& out, const Figure& obj) {
    out << obj.x << " " << obj.y << " " << obj.m_square << " "  << obj.name();
    return out;
}








