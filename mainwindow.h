#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "joystick_CTRL/joystick_ctrl.h"

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

private:
    Ui::MainWindow *ui;
    JoystickController *m_joystick;
};
#endif // MAINWINDOW_H
