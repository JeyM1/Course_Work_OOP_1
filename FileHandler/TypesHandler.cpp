//
// Created by admin on 04.12.2019.
//

#include <cstring>
#include "TypesHandler.h"
#include "../Exception.h"

void TypesHandler::save(std::ofstream& stream) {
    size_t nameLength = strlen(typeid(TypesHandler).name()) + 1;
    char* name = new char[nameLength];
    strcpy(name, typeid(TypesHandler).name());
    stream.write((char*)&(nameLength), sizeof(size_t));
    stream.write(name, nameLength * sizeof(char));
    delete[] name;
    stream.write((char*)&(this->length), sizeof(size_t));
    for (size_t i = 0; i < this->length; i++) {
        this->getNode(i)->data->save(stream);
    }
}

void TypesHandler::load(std::ifstream& stream) {
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
        stream.seekg((-1) * (long long)(classNameLength * sizeof(char) + sizeof(size_t)), ios::cur);
        if (object) {
            object->load(stream);
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
