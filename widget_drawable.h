#ifndef WIDGET_DRAWABLE_H
#define WIDGET_DRAWABLE_H

#include <QWidget>

namespace Ui {
class widget_drawable;
}

class widget_drawable : public QWidget
{
    Q_OBJECT

public:
    explicit widget_drawable(QWidget *parent = nullptr);
    ~widget_drawable();

private:
    Ui::widget_drawable *ui;
};

#endif // WIDGET_DRAWABLE_H
