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
    SL_List<FileHandler*(*)(std::string)> types;
    void init_all_types();
public:
    ArrayOfObjectsOnScreen();
    explicit ArrayOfObjectsOnScreen(SL_List<Figure*>&);
    void add(int idx, Figure*);
    void add(Figure*);
    void remove(int idx);
    void clear();
    size_t size();
    double calculateAverageSquare(FigureName::e_FigureNames name = FigureName::Figure);
    Point calculateAveragePoint(FigureName::e_FigureNames name = FigureName::Figure);

    void text_save(std::ofstream&) override;
    void text_load(std::ifstream&) override;
    void binary_save(std::ofstream&) override;
    void binary_load(std::ifstream&) override;
    void add_load_type(FileHandler*(*callback)(std::string));
    void sort_by_square();

    friend std::ostream& operator<<(std::ostream&, ArrayOfObjectsOnScreen&);
    Figure*operator[](int i);
};


#endif //COURSE_WORK_OOP_1_ARRAYOFOBJECTSONSCREEN_H
