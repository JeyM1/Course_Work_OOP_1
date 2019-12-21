#include <cmath>
#include <cstring>
#include "Ellipse.h"
#include "Exception.h"

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
void Ellipse::setRadiusVertical(double radiusVertical) { m_radius_vertical = radiusVertical; m_square = M_PI * m_radius_horizontal * m_radius_vertical; }
void Ellipse::setRadiusHorizontal(double radiusHorizontal) { m_radius_horizontal = radiusHorizontal; m_square = M_PI * m_radius_horizontal * m_radius_vertical; }

std::ostream &operator<<(std::ostream& out, const Ellipse& obj) {
    out << obj.x << " " << obj.y << " " << obj.m_square << " " << obj.name() << " " << obj.m_radius_vertical << " " <<
                                                                                            obj.m_radius_horizontal;
    return out;
}

void Ellipse::binary_save(std::ofstream& stream) {
    size_t nameLength = strlen(typeid(Ellipse).name()) + 1;
    char* name = new char[nameLength];
    strcpy(name, typeid(Ellipse).name());
    stream.write((char*)&(nameLength), sizeof(size_t));
    stream.write(name, nameLength * sizeof(char));
    delete[] name;
    Figure::binary_save(stream);
    stream.write((char*)&(this->m_radius_vertical), sizeof(double));
    stream.write((char*)&(this->m_radius_horizontal), sizeof(double));
}

void Ellipse::binary_load(std::ifstream& stream) {
    size_t nameLength = 0;
    stream.read((char*)&(nameLength), sizeof(size_t));
    char* name = new char[nameLength];
    stream.read(name, nameLength * sizeof(char));
    if (strcmp(name, typeid(Ellipse).name()) != 0) {
        throw WrongInputFileException();
    }
    delete[] name;
    Figure::binary_load(stream);
    stream.read((char*)&(this->m_radius_vertical), sizeof(double));
    stream.read((char*)&(this->m_radius_horizontal), sizeof(double));
}

void Ellipse::text_save(std::ofstream& stream) {
    stream << *this << "\n";
}

void Ellipse::text_load(std::ifstream& stream) {
    Figure::text_load(stream);
    stream >> this->m_radius_vertical >> this->m_radius_horizontal;
}

std::string Ellipse::getTypeIdName() {
    return typeid(Ellipse).name();
}

