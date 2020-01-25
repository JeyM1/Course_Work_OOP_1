#ifndef COURSE_WORK_OOP_1_ELLIPSE_H
#define COURSE_WORK_OOP_1_ELLIPSE_H


#include "Figure.h"

class Ellipse : public Figure {
    double m_radius_vertical;
    double m_radius_horizontal;
    std::string getTypeIdName() override;
public:
    Ellipse();
    Ellipse(double radiusVertical, double radiusHorizontal);
    Ellipse(int x, int y, double radiusVertical, double radiusHorizontal);
    ~Ellipse() override;

    double getRadiusVertical() const;
    double getRadiusHorizontal() const;
    void setRadiusHorizontal(double);
    void setRadiusVertical(double);

    void text_save(std::ofstream&) override;
    void text_load(std::ifstream&) override;
    void binary_save(std::ofstream&) override;
    void binary_load(std::ifstream&) override;

    friend std::ostream& operator<<(std::ostream&, const Ellipse&);
	bool operator <(const Figure&) override;
	bool operator >(const Figure&) override;
	Ellipse& operator =(const Ellipse&);
};


#endif //COURSE_WORK_OOP_1_ELLIPSE_H
