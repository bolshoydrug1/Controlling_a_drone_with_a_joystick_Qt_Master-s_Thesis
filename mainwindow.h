#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "joystick_CTRL/joystick_ctrl.h"
#include "f_select_ctrl.h"
#include "ui_f_select_ctrl.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onJoystickConnected(const QString &name);
    void onJoystickDisconnected();
    void onJoystickError(const QString &message);
    void onAxisChanged(int axis, int value);
    void onButtonPressed(int button);
    void onCommandReady(const QString &commandType, const QVariantMap &data);

    void on_pb_select_ctrl_clicked();

private:
    Ui::MainWindow *ui;
    Ui::F_select_ctrl* select_ctrl;
    JoystickController *m_joystick;
};
#endif // MAINWINDOW_H
