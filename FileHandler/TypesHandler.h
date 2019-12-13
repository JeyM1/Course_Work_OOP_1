#ifndef PRACT7_TYPESHANDLER_H
#define PRACT7_TYPESHANDLER_H


#include "FileHandler.h"
#include "..\SingleLinkedList\SL_List.h"

class TypesHandler : public SL_List<FileHandler*>, public FileHandler {
protected:
    SL_List<FileHandler*(*)(std::string)> types;
public:
    TypesHandler() : SL_List() {};
    ~TypesHandler() = default;;
    void save(std::ofstream&) override;
    void load(std::ifstream&) override;
    void add_load_type(FileHandler*(*callback)(std::string));
};


#endif //PRACT7_TYPESHANDLER_H
