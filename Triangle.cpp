#include <cmath>
#include <cstring>
#include "Triangle.h"
#include "Exception.h"

Triangle::Triangle() : Figure(FigureName::Triangle), m_points() {}
Triangle::Triangle(const Point& A, const Point& B, const Point& C) : m_points(A, B, C),
                                                                     Figure((A + B + C)/3, //get center of any triangle: (A + B + C)/3
                                                                             FigureName::Triangle) {
    /* Here using formula of getting square of triangle with only points available:
     * S = 1/2 * | x1 - x3  y1 - y3 |
     *           | x2 - x3  y2 - y3 |         */
    this->m_square = std::abs((((double)A.getX() - (double)C.getX()) * ((double)B.getY() - (double)C.getY())) -
                              (((double)B.getX() - (double)C.getX()) * ((double)A.getY() - (double)C.getY()))) / 2;
}
Triangle::~Triangle() = default;

Triangle::Points Triangle::getPoints() const { return m_points; }
void Triangle::setPoints(const Triangle::Points &points) { m_points = points; }

std::ostream &operator<<(std::ostream& out, const Triangle& obj) {
    out << obj.x << " " << obj.y << " " << obj.m_square << " "  << obj.name() << " " << obj.m_points;
    return out;
}

void Triangle::binary_save(std::ofstream& stream) {
    size_t nameLength = strlen(typeid(Triangle).name()) + 1;
    char* name = new char[nameLength];
    strcpy(name, typeid(Triangle).name());
    stream.write((char*)&(nameLength), sizeof(size_t));
    stream.write(name, nameLength * sizeof(char));
    delete[] name;
    Figure::binary_save(stream);
    m_points.A.binary_save(stream);
    m_points.B.binary_save(stream);
    m_points.C.binary_save(stream);
}

void Triangle::binary_load(std::ifstream& stream) {
    size_t nameLength = 0;
    stream.read((char*)&(nameLength), sizeof(size_t));
    char* name = new char[nameLength];
    stream.read(name, nameLength * sizeof(char));
    if (strcmp(name, typeid(Triangle).name()) != 0) {
        throw WrongInputFileException();
    }
    delete[] name;
    Figure::binary_load(stream);
    m_points.A.binary_load(stream);
    m_points.B.binary_load(stream);
    m_points.C.binary_load(stream);
}



