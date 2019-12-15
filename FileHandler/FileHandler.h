#ifndef PRACT5_6_FILEHANDLER_H
#define PRACT5_6_FILEHANDLER_H

#include <iostream>
#include <fstream>

class FileHandler {
public:
    virtual void text_save(std::ofstream&) = 0;
    virtual void text_load(std::ifstream&) = 0;
    virtual void binary_save(std::ofstream&) = 0;
    virtual void binary_load(std::ifstream&) = 0;
};

#endif //PRACT5_6_FILEHANDLER_H
