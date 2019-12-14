#ifndef PRACT7_TYPESHANDLER_H
#define PRACT7_TYPESHANDLER_H


#include "FileHandler.h"
#include "..\SingleLinkedList\SL_List.h"

class TypesHandler : public SL_List<FileHandler*>, public FileHandler {
    void init_all_types();
protected:
    SL_List<FileHandler*(*)(std::string)> types;
public:
    TypesHandler() : SL_List() { init_all_types(); }
    ~TypesHandler() = default;
    void binary_save(std::ofstream&) override;
    void binary_load(std::ifstream&) override;
    void add_load_type(FileHandler*(*callback)(std::string));
};


#endif //PRACT7_TYPESHANDLER_H
