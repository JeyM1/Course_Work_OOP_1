#include <cmath>
#include "Triangle.h"

Triangle::Triangle() : Figure(FigureName::Triangle), m_points() {}
Triangle::Triangle(const Point& A, const Point& B, const Point& C) : m_points(A, B, C),
                                                                     Figure((A + B + C)/3, //get center of any triangle: (A + B + C)/3
                                                                             FigureName::Triangle) {
    /* Here using formula of getting square of triangle with only points available:
     * S = 1/2 * | x1 - x3  y1 - y3 |
     *           | x2 - x3  y2 - y3 |         */
    this->m_square = std::abs((((double)A.getX() - (double)C.getX()) * ((double)B.getY() - (double)C.getY()))
                              - //--------------------------------------------------------------------------------------------
                              (((double)B.getX() - (double)C.getX()) * ((double)A.getY() - (double)C.getY()))) / 2;
}


Triangle::Points Triangle::getPoints() const {
    return m_points;
}

void Triangle::setPoints(const Triangle::Points &mPoints) {
    m_points = mPoints;
}

std::ostream &operator<<(std::ostream& out, const Triangle& obj) {
    out << obj.x << " " << obj.y << " " << obj.m_square << " "  << obj.name() << " " << obj.m_points;
    return out;
}


