#include <cstring>
#include "Rectangle.h"
#include "Exception.h"

Rectangle::Rectangle() : Figure(), a(0), b(0) {}
Rectangle::Rectangle(double a, double b) : Figure(FigureName::Rectangle), a(a), b(b) {
    this->m_square = a * b;
}
Rectangle::Rectangle(int x, int y, double a, double b) : Figure(x, y, FigureName::Rectangle, a*b), a(a), b(b) {}
Rectangle::~Rectangle() = default;

std::ostream &operator<<(std::ostream& out, const Rectangle& obj) {
    out << obj.x << " " << obj.y << " " << obj.m_square << " " << obj.name() << " " << obj.a << " " << obj.b;
    return out;
}

double Rectangle::getA() const { return a; }
void Rectangle::setA(double a) { this->a = a; }
double Rectangle::getB() const { return b; }
void Rectangle::setB(double b) { this->b = b; }

void Rectangle::binary_save(std::ofstream& stream) {
    size_t nameLength = strlen(typeid(Rectangle).name()) + 1;
    char* name = new char[nameLength];
    strcpy(name, typeid(Rectangle).name());
    stream.write((char*)&(nameLength), sizeof(size_t));
    stream.write(name, nameLength * sizeof(char));
    delete[] name;
    Figure::binary_save(stream);
    stream.write((char*)&(this->a), sizeof(double));
    stream.write((char*)&(this->b), sizeof(double));
}

void Rectangle::binary_load(std::ifstream& stream) {
    size_t nameLength = 0;
    stream.read((char*)&(nameLength), sizeof(size_t));
    char* name = new char[nameLength];
    stream.read(name, nameLength * sizeof(char));
    if (strcmp(name, typeid(Rectangle).name()) != 0) {
        throw WrongInputFileException();
    }
    delete[] name;
    Figure::binary_load(stream);
    stream.read((char*)&(this->a), sizeof(double));
    stream.read((char*)&(this->b), sizeof(double));
}



