#ifndef COURSE_WORK_OOP_1_TRIANGLE_H
#define COURSE_WORK_OOP_1_TRIANGLE_H


#include "Figure.h"

class Triangle : public Figure {
public:
    class Points{
    public:
        Point A;
        Point B;
        Point C;
        Points() : A(), B(), C() {}
        Points(const Point& top, const Point& left, const Point& right): A(top), B(left), C(right) {}
        friend std::ostream& operator<<(std::ostream& out, const Points& obj){
            return out << obj.A << " " << obj.B << " " << obj.C;
        }
    };
protected:
    Points m_points;
public:
    Triangle();
    Triangle(const Point& top, const Point& left, const Point& right);
    ~Triangle() override;

    Points getPoints() const;
    void setPoints(const Points& points);

    friend std::ostream& operator<<(std::ostream&, const Triangle&);
};


#endif //COURSE_WORK_OOP_1_TRIANGLE_H
