#include <cmath>
#include <cstring>
#include "Circle.h"
#include "Exception.h"

Circle::Circle() : Figure(FigureName::Circle), m_radius(0) {}
Circle::Circle(double radius) : Figure(FigureName::Circle), m_radius(radius) {
    this->m_square = M_PI * pow(radius, 2);
}
Circle::Circle(int x, int y) : Figure(x, y, FigureName::Circle), m_radius(0) {}
Circle::Circle(int x, int y, double radius) : Figure(x, y, FigureName::Circle), m_radius(radius) {
    this->m_square = M_PI * pow(radius, 2);
}
Circle::~Circle() = default;

double Circle::getRadius() const { return m_radius; }
void Circle::setRadius(double radius) { m_radius = radius; }

std::ostream &operator<<(std::ostream& out, const Circle& obj) {
    out << obj.x << " " << obj.y << " " << obj.m_square << " " << obj.name() << " " << obj.m_radius;
    return out;
}

Circle::Circle(const Circle& obj) : Figure(obj.x, obj.y, obj.m_figure_name, obj.m_square), m_radius(obj.m_radius) {}

void Circle::binary_save(std::ofstream& stream) {
    size_t nameLength = strlen(typeid(Circle).name()) + 1;
    char* name = new char[nameLength];
    strcpy(name, typeid(Circle).name());
    stream.write((char*)&(nameLength), sizeof(size_t));
    stream.write(name, nameLength * sizeof(char));
    delete[] name;
    Figure::binary_save(stream);
    stream.write((char*)&(this->m_radius), sizeof(double));
}

void Circle::binary_load(std::ifstream& stream) {
    size_t nameLength = 0;
    stream.read((char*)&(nameLength), sizeof(size_t));
    char* name = new char[nameLength];
    stream.read(name, nameLength * sizeof(char));
    if (strcmp(name, typeid(Circle).name()) != 0) {
        throw WrongInputFileException();
    }
    delete[] name;
    Figure::binary_load(stream);
    stream.read((char*)&(this->m_radius), sizeof(double));
}

void Circle::text_save(std::ofstream& stream) {
    stream << *this << endl;
}

void Circle::text_load(std::ifstream& stream) {
    Figure::text_load(stream);
    stream >> this->m_radius;
}

std::string Circle::getTypeIdName() {
    return typeid(Circle).name();
}
