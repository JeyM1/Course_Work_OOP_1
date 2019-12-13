#include <cmath>
#include "Ellipse.h"

Ellipse::Ellipse() : Figure(FigureName::Ellipse), m_radius_horizontal(0), m_radius_vertical(0) {}
Ellipse::Ellipse(double radiusVertical, double radiusHorizontal) :
                        Figure(FigureName::Ellipse, M_PI * radiusHorizontal * radiusVertical),
                                                                   m_radius_vertical(radiusVertical),
                                                                   m_radius_horizontal(radiusHorizontal) {}
Ellipse::Ellipse(int x, int y, double radiusVertical, double radiusHorizontal) : Figure(x, y, FigureName::Ellipse, M_PI * radiusHorizontal * radiusVertical),
                                                                                 m_radius_vertical(radiusVertical),
                                                                                 m_radius_horizontal(radiusHorizontal){}
Ellipse::~Ellipse() = default;

double Ellipse::getRadiusVertical() const { return m_radius_vertical; }
double Ellipse::getRadiusHorizontal() const { return m_radius_horizontal; }
void Ellipse::setRadiusVertical(double radiusVertical) { m_radius_vertical = radiusVertical; }
void Ellipse::setRadiusHorizontal(double radiusHorizontal) { m_radius_horizontal = radiusHorizontal; }

std::ostream &operator<<(std::ostream& out, const Ellipse& obj) {
    out << obj.x << " " << obj.y << " " << obj.m_square << " " << obj.name() << " " << obj.m_radius_vertical << " " <<
                                                                                            obj.m_radius_horizontal;
    return out;
}

