#ifndef DIALOG_FINDFIGURE_H
#define DIALOG_FINDFIGURE_H

#include <QDialog>
#include "ArrayOfObjectsOnScreen.h"

namespace Ui {
class Dialog_FindFigure;
}

class Dialog_FindFigure : public QDialog
{
	Q_OBJECT

public:
	explicit Dialog_FindFigure(ArrayOfObjectsOnScreen*, QWidget *parent = nullptr);
	~Dialog_FindFigure();

private slots:
	void on_btn_find_clicked();
	void on_CB_figure_type_activated(int index);
	void CB_first_time_clicked(const QString&);


private:
	Ui::Dialog_FindFigure *ui;
	ArrayOfObjectsOnScreen* list_handler;
};

#endif // DIALOG_FINDFIGURE_H
