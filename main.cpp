#include <iostream>
#include "Figure.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include "ArrayOfObjectsOnScreen.h"
#include "FileHandler/TypesHandler.h"

using std::cout;
using std::cin;
using std::endl;

/* TODO:
 *  All classes - binary read/write and text read/write
 *  Program Interface */


int main() {
    auto main_save = new TypesHandler();
    auto main_load = new TypesHandler();

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
    cout << main.calculateAverageSquare(FigureName::Circle) << endl;
    cout << main.calculateAveragePoint(FigureName::Circle) << endl;

    std::ofstream fout("objects.dat", std::ios::binary);
    /*main_save->push_back(&circle1);
    main_save->push_back(&triangle1);
    main_save->push_back(&rect1);
    main_save->push_back(&ellipse1);*/
    main_save->push_back(&main);
    main_save->binary_save(fout);
    fout.close();
    std::ifstream fin("objects.dat", std::ios::binary);
    main_load->binary_load(fin);
    ArrayOfObjectsOnScreen main2 = *dynamic_cast<ArrayOfObjectsOnScreen*>(main_load->getNode(0)->data);
    cout << main << endl;
    cout << main2 << endl;
    return 0;
}