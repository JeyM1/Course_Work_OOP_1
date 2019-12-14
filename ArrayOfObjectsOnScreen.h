#ifndef COURSE_WORK_OOP_1_ARRAYOFOBJECTSONSCREEN_H
#define COURSE_WORK_OOP_1_ARRAYOFOBJECTSONSCREEN_H


#include "Figure.h"
#include "SingleLinkedList/SL_List.h"
#include "Ellipse.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"

class ArrayOfObjectsOnScreen : public Point {
    SL_List<Figure*> m_figures;
    SL_List<Figure*(*)(std::string)> types;
    void init_all_types();
public:
    ArrayOfObjectsOnScreen();
    explicit ArrayOfObjectsOnScreen(SL_List<Figure*>&);
    void add(int idx, Figure*);
    void add(Figure*);
    double calculateAverageSquare(FigureName::e_FigureNames name = FigureName::Figure);
    Point calculateAveragePoint(FigureName::e_FigureNames name = FigureName::Figure);

    void binary_save(std::ofstream&) override;
    void binary_load(std::ifstream&) override;

    friend std::ostream& operator<<(std::ostream&, ArrayOfObjectsOnScreen&);
};


#endif //COURSE_WORK_OOP_1_ARRAYOFOBJECTSONSCREEN_H
