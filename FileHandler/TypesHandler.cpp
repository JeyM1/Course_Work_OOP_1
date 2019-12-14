#include <cstring>
#include "TypesHandler.h"
#include "../Exception.h"
#include "../ArrayOfObjectsOnScreen.h"

void TypesHandler::binary_save(std::ofstream& stream) {
    size_t nameLength = strlen(typeid(TypesHandler).name()) + 1;
    char* name = new char[nameLength];
    strcpy(name, typeid(TypesHandler).name());
    stream.write((char*)&(nameLength), sizeof(size_t));
    stream.write(name, nameLength * sizeof(char));
    delete[] name;
    stream.write((char*)&(this->length), sizeof(size_t));
    for (size_t i = 0; i < this->length; i++) {
        this->getNode(i)->data->binary_save(stream);
    }
}

void TypesHandler::binary_load(std::ifstream& stream) {
    size_t nameLength = 0;
    stream.read((char*)&(nameLength), sizeof(size_t));
    char* name = new char[nameLength];
    stream.read(name, nameLength*sizeof(char));
    if (strcmp(name, typeid(TypesHandler).name()) != 0) {
        throw WrongInputFileException();
    }
    delete[] name;

    size_t quantity = 0;
    stream.read((char*) & (quantity), sizeof(size_t));
    for (int i = 0; i < quantity; i++) {
        size_t classNameLength = 0;
        stream.read((char*)&(classNameLength), sizeof(size_t));
        char* className = new char[classNameLength];
        stream.read(className, classNameLength * sizeof(char));
        FileHandler* object = nullptr;
        for (size_t j = 0; j < this->types.size(); j++) {
            FileHandler* temp = this->types[j](string(className));
            if (temp) {
                object = temp;
                break;
            }
        }
        delete[] className;
        //cout << "DEBUG: " << (-1) * (long long)(classNameLength * sizeof(char) + sizeof(size_t)) << endl;
        stream.seekg((-1) * (long long)(classNameLength * sizeof(char) + sizeof(size_t)), ios::cur);
        if (object) {
            object->binary_load(stream);
        }
        else {
            throw UnknownDataTypeException();
        }
        this->push_back(object);
    }
}


void TypesHandler::add_load_type(FileHandler *(*callback)(std::string)) {
    this->types.push_back(callback);
}

void TypesHandler::init_all_types() {
    add_load_type([](std::string name) -> FileHandler* {
        if (name == typeid(Point).name()) {
            return new Point();
        }
        return nullptr;
    });
    add_load_type([](std::string name) -> FileHandler* {
        if (name == typeid(Figure).name()) {
            return new Figure();
        }
        return nullptr;
    });
    add_load_type([](std::string name) -> FileHandler* {
        if (name == typeid(Circle).name()) {
            return new Circle();
        }
        return nullptr;
    });
    add_load_type([](std::string name) -> FileHandler* {
        if (name == typeid(Triangle).name()) {
            return new Triangle();
        }
        return nullptr;
    });
    add_load_type([](std::string name) -> FileHandler* {
        if (name == typeid(Rectangle).name()) {
            return new Rectangle();
        }
        return nullptr;
    });
    add_load_type([](std::string name) -> FileHandler* {
        if (name == typeid(Ellipse).name()) {
            return new Ellipse();
        }
        return nullptr;
    });
    add_load_type([](std::string name) -> FileHandler* {
        if (name == typeid(ArrayOfObjectsOnScreen).name()) {
            return new ArrayOfObjectsOnScreen();
        }
        return nullptr;
    });
}
