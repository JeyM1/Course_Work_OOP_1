#ifndef COURSE_WORK_OOP_1_ELLIPSE_H
#define COURSE_WORK_OOP_1_ELLIPSE_H


#include "Figure.h"

class Ellipse : public Figure {
    double m_radius_vertical;
    double m_radius_horizontal;
public:
    Ellipse();
    Ellipse(double radiusVertical, double radiusHorizontal);
    Ellipse(int x, int y, double radiusVertical, double radiusHorizontal);
    ~Ellipse() override;

    double getRadiusVertical() const;
    double getRadiusHorizontal() const;
    void setRadiusHorizontal(double);
    void setRadiusVertical(double);

    void binary_save(std::ofstream&) override;
    void binary_load(std::ifstream&) override;

    friend std::ostream& operator<<(std::ostream&, const Ellipse&);
};


#endif //COURSE_WORK_OOP_1_ELLIPSE_H
