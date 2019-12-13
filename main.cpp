#include <iostream>
#include "Figure.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include "ArrayOfObjectsOnScreen.h"

using std::cout;
using std::cin;
using std::endl;

/* TODO:
 *  List of figures on the screen
 *  All classes - binary read/write and text read/write
 *  Program Interface */


int main() {
    Circle circle1(1, 1, 2);
    cout << circle1 << endl;
    Triangle triangle1(Point(10, 10), Point(5, 10), Point(-1, -1));
    cout << triangle1 << endl;
    Rectangle rect1(2, 2, 2 ,6);
    cout << rect1 << endl;
    Ellipse ellipse1(5, 5, 6, 4);
    cout << ellipse1 << endl;
    ArrayOfObjectsOnScreen main;
    main.add(&circle1);
    main.add(&triangle1);
    main.add(&rect1);
    main.add(&ellipse1);
    cout << main.calculateAverageSquare(FigureName(FigureName::Circle)) << endl;

    return 0;
}