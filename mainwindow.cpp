#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QJsonDocument>
#include "f_select_ctrl.h"
#include "ui_f_select_ctrl.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_joystick(new JoystickController(this))
{
    ui->setupUi(this);

    // Настройка подключения сигналов джойстика
    connect(m_joystick, &JoystickController::connected,
            this, &MainWindow::onJoystickConnected);
    connect(m_joystick, &JoystickController::disconnected,
            this, &MainWindow::onJoystickDisconnected);
    connect(m_joystick, &JoystickController::errorOccurred,
            this, &MainWindow::onJoystickError);
    connect(m_joystick, &JoystickController::axisChanged,
            this, &MainWindow::onAxisChanged);
    connect(m_joystick, &JoystickController::buttonPressed,
            this, &MainWindow::onButtonPressed);
    connect(m_joystick, &JoystickController::commandReady,
            this, &MainWindow::onCommandReady);

    // Инициализация джойстика
    if (!m_joystick->initialize(0)) {
        QMessageBox::warning(this, "Внимание",
                             "Джойстик не найден. Подключите устройство и перезапустите приложение.");
        ui->txt_status_bar->append("Джойстик не найден. Подключите устройство и перезапустите приложение");
    } else {
        m_joystick->start(20); // Опрос 50 раз в секунду
        ui->txt_status_bar->append("🎮 Джойстик готов");
    }
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onJoystickConnected(const QString &name) {
    ui->statusbar->showMessage("✅ Подключён: " + name, 5000);
    ui->txt_status_bar->append("✅ Подключён: " + name);
}

void MainWindow::onJoystickDisconnected() {
    ui->statusbar->showMessage("🔌 Джойстик отключён", 3000);
    QMessageBox::information(this, "Информация", "Джойстик был отключён");
}

void MainWindow::onJoystickError(const QString &message) {
    QMessageBox::critical(this, "Ошибка джойстика", message);
}

void MainWindow::onAxisChanged(int axis, int value) {
    // Пример: обновление статусной строки
    if (axis == 1) { // Левый стик Y
        QString dir = (value < -10000) ? "↑ ВПЕРЁД" : (value > 10000) ? "↓ НАЗАД" : "• СТОП";
        ui->statusbar->showMessage(dir + " (" + QString::number(value) + ")", 200);
    }
    if (axis == 0) { // Левый стик X
        QString dir = (value < -10000) ? "<- ВЛЕВО" : (value > 10000) ? "-> ВПРАВО" : "• СТОП";
        ui->statusbar->showMessage(dir + " (" + QString::number(value) + ")", 200);
    }
}

void MainWindow::onButtonPressed(int button) {
    ui->statusbar->showMessage("🔘 Кнопка " + QString::number(button) + " нажата", 500);
}

void MainWindow::onCommandReady(const QString &commandType, const QVariantMap &data) {
    // Здесь можно отправлять команду по сети
    // Например: m_commandSender->sendCommand(commandType, data);

    // Для отладки — выводим в консоль
    QJsonDocument doc = QJsonDocument::fromVariant(data);
    qDebug() << "📤 Команда:" << commandType << doc.toJson();
}

void MainWindow::on_pb_select_ctrl_clicked()
{
    F_select_ctrl* select_ctrl = new F_select_ctrl(nullptr);
    select_ctrl->setAttribute(Qt::WA_DeleteOnClose);  // Удалить только при закрытии
    select_ctrl->show();
}

