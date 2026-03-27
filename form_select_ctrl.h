#ifndef FORM_SELECT_CTRL_H
#define FORM_SELECT_CTRL_H

#include <QWidget>

namespace Ui {
class Form_select_ctrl;
}

class Form_select_ctrl : public QWidget
{
    Q_OBJECT

public:
    explicit Form_select_ctrl(QWidget *parent = nullptr);
    ~Form_select_ctrl();

private:
    Ui::Form_select_ctrl *ui;
};

#endif // FORM_SELECT_CTRL_H
