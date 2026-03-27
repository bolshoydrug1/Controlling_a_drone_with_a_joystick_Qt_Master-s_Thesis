#ifndef F_SELECT_CTRL_H
#define F_SELECT_CTRL_H

#include <QWidget>

namespace Ui {
class F_select_ctrl;
}

class F_select_ctrl : public QWidget
{
    Q_OBJECT

public:
    explicit F_select_ctrl(QWidget *parent = nullptr);
    ~F_select_ctrl();

private:
    Ui::F_select_ctrl *ui;
};

#endif // F_SELECT_CTRL_H
