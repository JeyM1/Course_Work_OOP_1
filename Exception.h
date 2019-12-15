#ifndef PRACT7_EXCEPTION_H
#define PRACT7_EXCEPTION_H

#include <string>

using namespace std;

class Exception : public std::exception{
public:
    Exception() = default;
    ~Exception() override = default;
    virtual string getMessage() { return this->what(); }
};

class WrongInputFileException : public Exception {
public:
    string getMessage() override {
        return string("Error: WrongInputFileException");
    }
};

class UnknownDataTypeException : public Exception  {
public:
    string getMessage() override {
        return string("Error: UnknownDataTypeException");
    }
};

class IndexOutOfBoundsException : public Exception  {
public:
    string getMessage() override {
        return string("Error: IndexOutOfBoundsException");
    }
};

class CastFailedException : public Exception  {
public:
    string getMessage() override {
        return string("Error: CastFailedException");
    }
};



#endif //PRACT7_EXCEPTION_H
