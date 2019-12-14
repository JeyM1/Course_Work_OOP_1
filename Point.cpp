#include <cstring>
#include "Point.h"
#include "Exception.h"

Point::Point() : x(0), y(0) {}
Point::Point(int x, int y) : x(x), y(y) {}
Point::~Point() = default;
Point::Point(const Point& obj) : x(obj.x), y(obj.y) {}

int Point::getX() const { return x; }
int Point::getY() const { return y; }

void Point::setX(int x) { this->x = x; }
void Point::setY(int y) { this->y = y; }

std::ostream &operator<<(std::ostream& out, const Point& obj) {
    return out << obj.x << "_" << obj.y;
}

Point Point::operator+(const Point& obj) const {
    return Point(this->x + obj.x, this->y + obj.y);
}

Point Point::operator/(const Point& obj) const {
    return Point(this->x/obj.x, this->y / obj.y);
}

Point Point::operator/(int num) const {
    return Point(this->x / num, this->y / num);
}

void Point::binary_save(std::ofstream& stream) {
    size_t nameLength = strlen(typeid(Point).name()) + 1;
    char* name = new char[nameLength];
    strcpy(name, typeid(Point).name());
    stream.write((char*)&(nameLength), sizeof(size_t));
    stream.write(name, nameLength * sizeof(char));
    delete[] name;
    stream.write((char*)&(this->x), sizeof(int));
    stream.write((char*)&(this->y), sizeof(int));
}

void Point::binary_load(std::ifstream& stream) {
    size_t nameLength = 0;
    stream.read((char*)&(nameLength), sizeof(size_t));
    char* name = new char[nameLength];
    stream.read(name, nameLength * sizeof(char));
    if (strcmp(name, typeid(Point).name()) != 0) {
        throw WrongInputFileException();
    }
    delete[] name;
    stream.read((char*)&(this->x), sizeof(int));
    stream.read((char*)&(this->y), sizeof(int));
}


