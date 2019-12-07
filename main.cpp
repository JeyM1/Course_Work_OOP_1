#include <iostream>
#include "Figure.h"
#include "Circle.h"

using std::cout;
using std::cin;
using std::endl;



int main() {
    Circle circle1(1, 1, FigureName::Circle);
    cout << circle1 << endl;

    return 0;
}