#include <cstring>
#include "Figure.h"
#include "Exception.h"

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
Point Figure::getPoint() {
    return Point(this->x, this->y);
}

std::ostream &operator<<(std::ostream& out, const Figure& obj) {
    out << obj.x << " " << obj.y << " " << obj.m_square << " "  << obj.name();
    return out;
}

void Figure::binary_save(std::ofstream& stream) {
    size_t nameLength = strlen(typeid(Figure).name()) + 1;
    char* name = new char[nameLength];
    strcpy(name, typeid(Figure).name());
    stream.write((char*)&(nameLength), sizeof(size_t));
    stream.write(name, nameLength * sizeof(char));
    delete[] name;
    Point::binary_save(stream);
    stream.write((char*)&(this->m_square), sizeof(double));
    stream.write((char*)&(this->m_figure_name), sizeof(e_FigureNames));
}

void Figure::binary_load(std::ifstream& stream) {
    size_t nameLength = 0;
    stream.read((char*)&(nameLength), sizeof(size_t));
    char* name = new char[nameLength];
    stream.read(name, nameLength * sizeof(char));
    if (strcmp(name, typeid(Figure).name()) != 0) {
        throw WrongInputFileException();
    }
    delete[] name;
    Point::binary_load(stream);
    stream.read((char*)&(this->m_square), sizeof(double));
    stream.read((char*)&(this->m_figure_name), sizeof(e_FigureNames));
}

void Figure::text_save(std::ofstream& stream) {
    stream << *this << "\n";
}

void Figure::text_load(std::ifstream& stream) {
    stream >> this->x >> this->y >> this->m_square;
    std::string buf;
    stream >> buf;
    if(buf == FigureName(FigureName::Circle).name()){
        this->m_figure_name = FigureName::Circle;
    } else if(buf == FigureName(FigureName::Triangle).name()){
        this->m_figure_name = FigureName::Triangle;
    } else if(buf == FigureName(FigureName::Rectangle).name()){
        this->m_figure_name = FigureName::Rectangle;
    } else if(buf == FigureName(FigureName::Ellipse).name()){
        this->m_figure_name = FigureName::Ellipse;
    }
}

std::string Figure::getTypeIdName() {
    return typeid(Figure).name();
}

bool Figure::operator <(const Figure& obj){
    return this->m_square < obj.m_square;
}

bool Figure::operator >(const Figure& obj){
    return this->m_square > obj.m_square;
}

bool Figure::operator ==(const Figure& obj){
    return (this->m_square == obj.m_square) && this->m_figure_name == obj.m_figure_name;
}

bool Figure::operator >=(const Figure& obj){
    return this->m_square >= obj.m_square;
}

bool Figure::operator <=(const Figure& obj){
    return this->m_square <= obj.m_square;
}
