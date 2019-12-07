#ifndef COURSE_WORK_OOP_1_FIGURE_H
#define COURSE_WORK_OOP_1_FIGURE_H


#include "Point.h"
#include "FigureName.h"
#include <iostream>


class Figure : public Point, public FigureName { //Point - center of Figure
protected:
    double m_square;
public:
    Figure();
    explicit Figure(double mSquare);
    explicit Figure(e_FigureNames names);
    Figure(int x, int y, e_FigureNames names);
    Figure(int x, int y, double square);
    Figure(int x, int y);

    double getSquare() const;
    void setSquare(double mSquare);

    friend std::ostream& operator<<(std::ostream&, const Figure&);
};


#endif //COURSE_WORK_OOP_1_FIGURE_H
