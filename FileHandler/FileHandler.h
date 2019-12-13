#ifndef PRACT5_6_FILEHANDLER_H
#define PRACT5_6_FILEHANDLER_H

#include <iostream>
#include <fstream>

class FileHandler {
public:
    virtual void save(std::ofstream&) = 0;
    virtual void load(std::ifstream&) = 0;
};

#endif //PRACT5_6_FILEHANDLER_H
