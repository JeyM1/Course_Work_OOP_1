#ifndef COURSE_WORK_OOP_1_RECTANGLE_H
#define COURSE_WORK_OOP_1_RECTANGLE_H


#include "Figure.h"

class Rectangle : public Figure {
    double a;
    double b;
    std::string getTypeIdName() override;
public:
    Rectangle();
    Rectangle(double a, double b);
    Rectangle(int x, int y, double a, double b);
    ~Rectangle() override;

    double getA() const;
    double getB() const;
    void setB(double b);
    void setA(double a);

    void text_save(std::ofstream&) override;
    void text_load(std::ifstream&) override;
    void binary_save(std::ofstream&) override;
    void binary_load(std::ifstream&) override;

    friend std::ostream& operator<<(std::ostream&, const Rectangle&);
	bool operator <(const Figure&) override;
	bool operator >(const Figure&) override;
	Rectangle& operator =(const Rectangle&);
};


#endif //COURSE_WORK_OOP_1_RECTANGLE_H
