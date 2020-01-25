#ifndef DIALOG_FOUNDFIGURES_H
#define DIALOG_FOUNDFIGURES_H

#include <QDialog>
#include "ArrayOfObjectsOnScreen.h"
#include "dialog_findfigure.h"

namespace Ui {
class Dialog_FoundFigures;
}

class Dialog_FoundFigures : public QDialog
{
	Q_OBJECT

public:
	explicit Dialog_FoundFigures(int mode, std::vector<int>&, ArrayOfObjectsOnScreen*, Dialog_FindFigure*);
	~Dialog_FoundFigures();

private:
	Ui::Dialog_FoundFigures *ui;
	ArrayOfObjectsOnScreen* list_handler;
	std::vector<int> found;
	int mode;
	void tableUpdate();
};

#endif // DIALOG_FOUNDFIGURES_H
