#include "ArrayOfObjectsOnScreen.h"

ArrayOfObjectsOnScreen::ArrayOfObjectsOnScreen() : m_figures() {}
ArrayOfObjectsOnScreen::ArrayOfObjectsOnScreen(SL_List<Figure*>& figures) : m_figures(figures) {
    for(int i = 0; i < m_figures.size(); i++){
        this->x += m_figures[i]->getX();
        this->y += m_figures[i]->getY();
    }
    this->x /= m_figures.size();
    this->y /= m_figures.size();
}

void ArrayOfObjectsOnScreen::add(int idx, Figure* data){
    m_figures.insert(idx, data);
}

void ArrayOfObjectsOnScreen::add(Figure* data) {
    m_figures.push_back(data);
}

double ArrayOfObjectsOnScreen::calculateAverageSquare(FigureName name) {
    double avg = 0;
    int calculated_objcts = 0;
    for(int i = 0; i < m_figures.size(); i++){
        if(m_figures[i]->name() == name.name() || name.getFigureName() == FigureName::Figure){
            avg += m_figures[i]->getSquare();
            calculated_objcts++;
        }
    }
    return avg/calculated_objcts;
}
