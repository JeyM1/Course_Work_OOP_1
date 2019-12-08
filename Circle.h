#ifndef COURSE_WORK_OOP_1_CIRCLE_H
#define COURSE_WORK_OOP_1_CIRCLE_H


#include "Figure.h"
//TODO: Circle needs to be derived of Ellipse
class Circle : public Figure {
    double m_radius;
public:
    Circle();
    explicit Circle(double radius);
    Circle(int x, int y);
    Circle(int x, int y, double radius);
    Circle(const Circle&);
    ~Circle() override;

    double getRadius() const;
    void setRadius(double);

    friend std::ostream& operator<<(std::ostream&, const Circle&);
};


#endif //COURSE_WORK_OOP_1_CIRCLE_H
