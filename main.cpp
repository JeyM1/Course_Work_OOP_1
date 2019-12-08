#include <iostream>
#include "Figure.h"
#include "Circle.h"
#include "Triangle.h"

using std::cout;
using std::cin;
using std::endl;

/* TODO: POINT: int or double in Qt?
 *  Rectangle class
 *  Ellipse class
 *  List of figures on the screen
 *  All classes - binary read/write and text read/write
 *  Program Interface */


int main() {
    Circle circle1(1, 1, 2);
    cout << circle1 << endl;
    Triangle triangle1(Point(10, 10), Point(5, 10), Point(-1, -1));
    cout << triangle1 << endl;
    return 0;
}