#include <cstring>
#include <iomanip>
#include "Rectangle.h"
#include "Exception.h"

Rectangle::Rectangle() : Figure(), a(0), b(0) {}
Rectangle::Rectangle(double a, double b) : Figure(FigureName::Rectangle), a(a), b(b) {
    this->m_square = a * b;
}
Rectangle::Rectangle(int x, int y, double a, double b) : Figure(x, y, FigureName::Rectangle, a*b), a(a), b(b) {}
Rectangle::~Rectangle() = default;

double Rectangle::getA() const { return a; }
void Rectangle::setA(double a) { this->a = a; this->m_square = a * b; }
double Rectangle::getB() const { return b; }
void Rectangle::setB(double b) { this->b = b; this->m_square = a * b; }

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

void Rectangle::text_save(std::ofstream& stream) {
    stream << *this << endl;
}

void Rectangle::text_load(std::ifstream& stream) {
    Figure::text_load(stream);
    stream >> a >> b;
}

std::string Rectangle::getTypeIdName() {
    return typeid(Rectangle).name();
}


std::ostream& operator<<(std::ostream& out, const Rectangle& obj) {
	out << obj.x << " " << obj.y << " " << std::fixed << setprecision(10) << obj.m_square << " " << obj.name() << " "
	    << std::fixed << setprecision(10) << obj.a << " " << std::fixed << setprecision(10) << obj.b;
	return out;
}

bool Rectangle::operator <(const Figure& obj) {
	const Rectangle* other = dynamic_cast<const Rectangle*>(&obj);
	if(!other)
		throw CastFailedException();
	return (this->a * this->b) < (other->a * other->b);
}

bool Rectangle::operator >(const Figure& obj) {
	const Rectangle* other = dynamic_cast<const Rectangle*>(&obj);
	if(!other)
		throw CastFailedException();
	return (this->a * this->b) < (other->a * other->b);
}

Rectangle& Rectangle::operator =(const Rectangle& obj) {
	Figure::operator=(obj);
	this->a = obj.a;
	this->b = obj.b;
	return *this;
}
