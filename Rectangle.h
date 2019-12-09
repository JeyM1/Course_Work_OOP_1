#ifndef COURSE_WORK_OOP_1_RECTANGLE_H
#define COURSE_WORK_OOP_1_RECTANGLE_H


#include "Figure.h"

class Rectangle : public Figure {
    double a;
    double b;
public:
    Rectangle();
    Rectangle(double a, double b);
    Rectangle(int x, int y, double a, double b);
    ~Rectangle() override;

    friend std::ostream& operator<<(std::ostream&, const Rectangle&);
};


#endif //COURSE_WORK_OOP_1_RECTANGLE_H
