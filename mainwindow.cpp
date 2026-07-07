#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QJsonDocument>
#include <QSerialPortInfo>
#include "f_select_ctrl.h"
#include "ui_f_select_ctrl.h"

namespace {
const QStringList kBaudRates = {"9600", "19200", "38400", "57600", "115200"};
const QString kDefaultBaudRate = "115200";
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_joystick(new JoystickController(this))
{
    ui->setupUi(this);

    qRegisterMetaType<TelemetryFrame_t>("TelemetryFrame_t");

    ui->cb_baud_rate->addItems(kBaudRates);
    ui->cb_baud_rate->setCurrentText(kDefaultBaudRate);
    populateComPorts();

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
    stopTelemetryReceiver();
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

void MainWindow::populateComPorts()
{
    const QString previous = ui->cb_com_port->currentText();
    ui->cb_com_port->clear();
    for (const QSerialPortInfo &info : QSerialPortInfo::availablePorts())
        ui->cb_com_port->addItem(info.portName());

    const int idx = ui->cb_com_port->findText(previous);
    if (idx >= 0)
        ui->cb_com_port->setCurrentIndex(idx);
}

void MainWindow::on_pb_refresh_com_clicked()
{
    populateComPorts();
}

void MainWindow::on_pb_connect_com_clicked()
{
    if (m_telemetryThread) {
        stopTelemetryReceiver();
        ui->pb_connect_com->setText("Подключиться");
        ui->txt_status_bar->append("🔌 Отключено от COM-порта");
        return;
    }

    const QString portName = ui->cb_com_port->currentText();
    if (portName.isEmpty()) {
        QMessageBox::warning(this, "Внимание", "COM порт не выбран");
        return;
    }
    const qint32 baudRate = ui->cb_baud_rate->currentText().toInt();
    startTelemetryReceiver(portName, baudRate);
}

void MainWindow::startTelemetryReceiver(const QString &portName, qint32 baudRate)
{
    m_telemetryThread = new QThread(this);
    m_telemetryReceiver = new TelemetryReceiver();
    m_telemetryReceiver->moveToThread(m_telemetryThread);

    connect(m_telemetryThread, &QThread::finished, m_telemetryReceiver, &QObject::deleteLater);
    connect(m_telemetryReceiver, &TelemetryReceiver::frameReceived, this, &MainWindow::onTelemetryFrame);
    connect(m_telemetryReceiver, &TelemetryReceiver::connected, this, &MainWindow::onTelemetryConnected);
    connect(m_telemetryReceiver, &TelemetryReceiver::disconnected, this, &MainWindow::onTelemetryDisconnected);
    connect(m_telemetryReceiver, &TelemetryReceiver::errorOccurred, this, &MainWindow::onTelemetryError);

    m_telemetryThread->start();
    QMetaObject::invokeMethod(m_telemetryReceiver, "openPort", Qt::QueuedConnection,
                               Q_ARG(QString, portName), Q_ARG(qint32, baudRate));
}

void MainWindow::stopTelemetryReceiver()
{
    if (!m_telemetryThread)
        return;

    QMetaObject::invokeMethod(m_telemetryReceiver, "closePort", Qt::QueuedConnection);
    m_telemetryThread->quit();
    m_telemetryThread->wait();
    delete m_telemetryThread;
    m_telemetryThread = nullptr;
    m_telemetryReceiver = nullptr;
}

void MainWindow::onTelemetryConnected()
{
    ui->pb_connect_com->setText("Отключиться");
    ui->txt_status_bar->append("✅ COM-порт открыт, приём телеметрии запущен");
}

void MainWindow::onTelemetryDisconnected()
{
    ui->txt_status_bar->append("🔌 COM-порт закрыт");
}

void MainWindow::onTelemetryError(const QString &message)
{
    QMessageBox::critical(this, "Ошибка телеметрии", message);
    ui->txt_status_bar->append("❌ " + message);
    stopTelemetryReceiver();
    ui->pb_connect_com->setText("Подключиться");
}

void MainWindow::onTelemetryFrame(TelemetryFrame_t frame)
{
    ui->txt_hight_RF->setText(QString::number(frame.height_agl_m * 100.0, 'f', 1));
    ui->txt_temperature->setText(QString::number(frame.temperature_c, 'f', 1));
    ui->txt_pressure->setText(QString::number(frame.pressure_mmhg, 'f', 1));
    ui->txt_altitude->setText(QString::number(frame.altitude_m, 'f', 1));
    ui->txt_bat_proc->setText(QString::number(frame.bat_procent));
    ui->txt_width->setText(QString::number(frame.width_gps / 1e7, 'f', 7));
    ui->txt_long->setText(QString::number(frame.longitude_gps / 1e7, 'f', 7));
    ui->txt_angle_north->setText(QString::number(frame.angle_from_north));
    ui->txt_kvadro_error->setText(QString::number(frame.error));
}

