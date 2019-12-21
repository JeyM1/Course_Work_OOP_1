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
Triangle::Points& Triangle::getrPoints() { return m_points; }
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

void Triangle::text_save(std::ofstream& stream) {
    stream << *this << "\n";
}

void Triangle::text_load(std::ifstream& stream) {
    Figure::text_load(stream);
    this->m_points.A.text_load(stream);
    this->m_points.B.text_load(stream);
    this->m_points.C.text_load(stream);
}

std::string Triangle::getTypeIdName() {
    return typeid(Triangle).name();
}

void Triangle::recalculateSquare(){
    this->m_square = std::abs((((double)m_points.A.getX() - (double)m_points.C.getX()) * ((double)m_points.B.getY() - (double)m_points.C.getY())) -
                              (((double)m_points.B.getX() - (double)m_points.C.getX()) * ((double)m_points.A.getY() - (double)m_points.C.getY()))) / 2;
}

