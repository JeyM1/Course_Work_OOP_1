#include "FigureName.h"

const char* const FigureName::_names[] = {"Figure", "Circle", "Triangle", "Rectangle", "Ellipse"};

FigureName::FigureName() : m_figure_name(FigureName::Figure) {}
FigureName::FigureName(FigureName::e_FigureNames FigureName) : m_figure_name(FigureName) {}

const char *FigureName::name() const {
    return FigureName::_names[m_figure_name];
}

FigureName::e_FigureNames FigureName::getFigureName() const {
    return m_figure_name;
}
