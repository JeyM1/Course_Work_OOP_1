#ifndef COURSE_WORK_OOP_1_POINT_H
#define COURSE_WORK_OOP_1_POINT_H

#include <iostream>
#include "Object.h"
#include "FileHandler/FileHandler.h"


class Point : public Object, public FileHandler {
protected:
    int x;
    int y;
public:
    Point();
    Point(int x, int y);
    Point(const Point&);
    virtual ~Point();

    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);

    void text_save(std::ofstream&) override;
    void text_load(std::ifstream&) override;
    void binary_save(std::ofstream&) override;
    void binary_load(std::ifstream&) override;

    friend std::ostream& operator<<(std::ostream&, const Point&);
    Point operator +(const Point&) const;
    Point operator /(const Point&) const;
    Point operator /(int) const;
    Point& operator +=(const Point&);
    Point& operator =(const Point&);
};


#endif //COURSE_WORK_OOP_1_POINT_H
