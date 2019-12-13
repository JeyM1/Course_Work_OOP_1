#ifndef COURSE_WORK_OOP_1_ARRAYOFOBJECTSONSCREEN_H
#define COURSE_WORK_OOP_1_ARRAYOFOBJECTSONSCREEN_H


#include "Figure.h"
#include "SingleLinkedList/SL_List.h"

class ArrayOfObjectsOnScreen : public Point {
    SL_List<Figure*> m_figures;
public:
    ArrayOfObjectsOnScreen();
    explicit ArrayOfObjectsOnScreen(SL_List<Figure*>&);
    void add(int idx, Figure*);
    void add(Figure*);
    double calculateAverageSquare(FigureName name = FigureName(FigureName::Figure));
};


#endif //COURSE_WORK_OOP_1_ARRAYOFOBJECTSONSCREEN_H
