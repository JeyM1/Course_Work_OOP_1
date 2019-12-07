#include <iostream>
#include "Figure.h"

using std::cout;
using std::cin;
using std::endl;



int main() {
    Figure circle1(1, 1, FigureName::Circle);
    cout << circle1 << endl;
    Figure fig1;
    cout << fig1 << endl;
    return 0;
}