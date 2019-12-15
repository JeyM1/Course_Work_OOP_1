#include <cstring>
#include "ArrayOfObjectsOnScreen.h"
#include "Exception.h"



ArrayOfObjectsOnScreen::ArrayOfObjectsOnScreen() : m_figures(), Point() { init_all_types(); }
ArrayOfObjectsOnScreen::ArrayOfObjectsOnScreen(SL_List<Figure*>& figures) : m_figures(figures) {
    init_all_types();
    for(int i = 0; i < m_figures.size(); i++){
        this->x += m_figures[i]->getX();
        this->y += m_figures[i]->getY();
    }
    this->x /= m_figures.size();
    this->y /= m_figures.size();
}

void ArrayOfObjectsOnScreen::add(int idx, Figure* data){
    m_figures.insert(idx, data);
}

void ArrayOfObjectsOnScreen::add(Figure* data) {
    m_figures.push_back(data);
    int _x = 0, _y  = 0;
    for(int i = 0; i < m_figures.size(); i++){
        _x += m_figures[i]->getX();
        _y += m_figures[i]->getY();
    }
    this->x = _x/(int)m_figures.size();
    this->y = _y/(int)m_figures.size();
}

double ArrayOfObjectsOnScreen::calculateAverageSquare(FigureName::e_FigureNames name) {
    double avg = 0;
    int calculated_objcts = 0;
    for(int i = 0; i < m_figures.size(); i++){
        if(m_figures[i]->getFigureName() == name || name == FigureName::Figure){
            avg += m_figures[i]->getSquare();
            calculated_objcts++;
        }
    }
    return avg/calculated_objcts;
}

Point ArrayOfObjectsOnScreen::calculateAveragePoint(FigureName::e_FigureNames name) {
    if(name == FigureName::Figure)
        return Point(this->x, this->y);

    Point avg;
    int calculated_objcts = 0;
    for(int i = 0; i < m_figures.size(); i++){
        if(m_figures[i]->getFigureName() == name){
            avg = avg + *(Point*)m_figures[i];
            calculated_objcts++;
        }
    }
    return avg/calculated_objcts;
}

void ArrayOfObjectsOnScreen::binary_save(std::ofstream& stream) {
    size_t nameLength = strlen(typeid(ArrayOfObjectsOnScreen).name()) + 1;
    char* name = new char[nameLength];
    strcpy(name, typeid(ArrayOfObjectsOnScreen).name());
    stream.write((char*)&(nameLength), sizeof(size_t));
    stream.write(name, nameLength * sizeof(char));
    delete[] name;
    Point::binary_save(stream);
    size_t list_size = this->m_figures.size();
    stream.write((char*)&list_size, sizeof(size_t));
    for(size_t i = 0; i < list_size; i++){
        m_figures[i]->binary_save(stream);
    }
}

void ArrayOfObjectsOnScreen::binary_load(std::ifstream& stream) {
    size_t nameLength = 0;
    stream.read((char*)&(nameLength), sizeof(size_t));
    char* name = new char[nameLength];
    stream.read(name, nameLength * sizeof(char));
    if (strcmp(name, typeid(ArrayOfObjectsOnScreen).name()) != 0) {
        throw WrongInputFileException();
    }
    delete[] name;
    Point::binary_load(stream);
    size_t list_size = 0;
    stream.read((char*)&list_size, sizeof(size_t));
    for(size_t i = 0; i < list_size; i++){
        size_t classNameLength = 0;
        stream.read((char*)&(classNameLength), sizeof(size_t));
        char* className = new char[classNameLength];
        stream.read(className, classNameLength * sizeof(char));
        FileHandler* _object = nullptr;
        for (size_t j = 0; j < this->types.size(); j++) {
            FileHandler* temp = this->types[j](string(className));
            if (temp) {
                _object = temp;
                break;
            }
        }
        delete[] className;
        stream.seekg((-1) * (long long)(classNameLength * sizeof(char) + sizeof(size_t)), ios::cur);
        if (_object) {
            _object->binary_load(stream);
        }
        else {
            throw UnknownDataTypeException();
        }
        this->m_figures.push_back(dynamic_cast<Figure *>(_object));
    }
}

void ArrayOfObjectsOnScreen::init_all_types() {
    types.push_back([](std::string name) -> FileHandler* {
        if (name == typeid(Circle).name()) {
            return new Circle();
        }
        return nullptr;
    });
    types.push_back([](std::string name) -> FileHandler* {
        if (name == typeid(Triangle).name()) {
            return new Triangle();
        }
        return nullptr;
    });
    types.push_back([](std::string name) -> FileHandler* {
        if (name == typeid(Rectangle).name()) {
            return new Rectangle();
        }
        return nullptr;
    });
    types.push_back([](std::string name) -> FileHandler* {
        if (name == typeid(Ellipse).name()) {
            return new Ellipse();
        }
        return nullptr;
    });
}

void ArrayOfObjectsOnScreen::add_load_type(FileHandler *(*callback)(std::string)) {
    this->types.push_back(callback);
}

std::ostream &operator<<(std::ostream& out, ArrayOfObjectsOnScreen& obj) {
    cout << obj.x << " " << obj.y << endl;
    for(int i{0}; i < obj.m_figures.size(); i++){
        out << *obj.m_figures[i] << endl;
    }
    return out;
}

void ArrayOfObjectsOnScreen::clear() {
    this->m_figures = SL_List<Figure*>();
    this->x = 0;
    this->y = 0;
}

Figure *ArrayOfObjectsOnScreen::operator[](int i) {
    return m_figures[i];
}

size_t ArrayOfObjectsOnScreen::size() {
    return m_figures.size();
}

void ArrayOfObjectsOnScreen::text_save(std::ofstream& stream) {
    stream << typeid(ArrayOfObjectsOnScreen).name() << " "<< this->m_figures.size() << " " << this->x << " "
                                                                                                << this->y << "\n";
    for(int i = 0; i < m_figures.size(); i++){
        stream << m_figures[i]->getTypeIdName() << " ";
        m_figures[i]->text_save(stream);
    }
}

void ArrayOfObjectsOnScreen::text_load(std::ifstream& stream) {
    std::string buf;
    stream >> buf;
    size_t quantity = 0;
    if(buf == typeid(ArrayOfObjectsOnScreen).name()){
        stream >> quantity >> this->x >> this->y;
        for(int i = 0; i < quantity; i++){
            buf.clear();
            stream >> buf;
            Figure* obj = nullptr;
            for(int el = 0; el < this->types.size(); el++){
                FileHandler* _tmp = this->types[el](buf);
                if(_tmp){
                    obj = dynamic_cast<Figure*>(_tmp);
                    break;
                }
            }
            if(obj){
                obj->text_load(stream);
            } else throw UnknownDataTypeException();
            this->m_figures.push_back(obj);
        }
    } else throw WrongInputFileException();
}

