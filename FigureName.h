#ifndef COURSE_WORK_OOP_1_FIGURENAME_H
#define COURSE_WORK_OOP_1_FIGURENAME_H



class FigureName {
    static const char* const _names[];
public:
    enum e_FigureNames {Figure, Circle, Triangle, Rectangle, Ellipse, SIZE};
protected:
    e_FigureNames m_figure_name;
public:
    FigureName();
    explicit FigureName(e_FigureNames);
    const char* name() const;

	e_FigureNames getFigureName() const;
};


#endif //COURSE_WORK_OOP_1_FIGURENAME_H
