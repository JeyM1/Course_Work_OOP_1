#ifndef PRACT7_EXCEPTION_H
#define PRACT7_EXCEPTION_H

#include <string>
#include <QException>

using namespace std;

class Exception : public QException {//: public std::exception{
public:
    Exception() = default;
    void raise() const override { throw *this; }
    Exception *clone() const override { return new Exception(*this); }
    virtual string getMessage() { return string("ERROR!"); }
};

class WrongInputFileException : public Exception {
public:
    void raise() const override { throw *this; }
    WrongInputFileException *clone() const override { return new WrongInputFileException(*this); }
    string getMessage() override {
        return string("Error: WrongInputFileException");
    }
};

class UnknownDataTypeException : public Exception  {
public:
    void raise() const override { throw *this; }
    UnknownDataTypeException *clone() const override { return new UnknownDataTypeException(*this); }
    string getMessage() override {
        return string("Error: UnknownDataTypeException");
    }
};

class IndexOutOfBoundsException : public Exception  {
public:
    void raise() const override { throw *this; }
    IndexOutOfBoundsException *clone() const override { return new IndexOutOfBoundsException(*this); }
    string getMessage() override {
        return string("Error: IndexOutOfBoundsException");
    }
};

class CastFailedException : public Exception  {
public:
    void raise() const override { throw *this; }
    CastFailedException *clone() const override { return new CastFailedException(*this); }
    string getMessage() override {
        return string("Error: CastFailedException");
    }
};



#endif //PRACT7_EXCEPTION_H
