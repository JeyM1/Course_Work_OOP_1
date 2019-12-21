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
    explicit Figure(e_FigureNames name);
    Figure(int x, int y, e_FigureNames name);
    Figure(int x, int y, double square);
    Figure(int x, int y);
    Figure(const Point& point, e_FigureNames name);
    Figure(e_FigureNames name, double square);
    Figure(int x, int y, e_FigureNames names, double mSquare);
    Figure(const Figure&);
    ~Figure() override;

    double getSquare() const;
    Point getPoint();
    void setSquare(double mSquare);
    virtual std::string getTypeIdName();

    void text_save(std::ofstream&) override;
    void text_load(std::ifstream&) override;
    void binary_save(std::ofstream&) override;
    void binary_load(std::ifstream&) override;

    bool operator >(const Figure&);
    bool operator <(const Figure&);
    bool operator ==(const Figure&);
    bool operator >=(const Figure&);
    bool operator <=(const Figure&);
    friend std::ostream& operator<<(std::ostream&, const Figure&);
};


#endif //COURSE_WORK_OOP_1_FIGURE_H
