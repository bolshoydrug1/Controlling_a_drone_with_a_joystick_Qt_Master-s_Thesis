#include "joystick_ctrl.h"
#include <SDL2/SDL.h>
#include <QDebug>
#include <QDateTime>

JoystickController::JoystickController(QObject *parent)
    : QObject(parent), m_pollTimer(new QTimer(this)) {

    // Подключаем таймер к слоту опроса
    connect(m_pollTimer, &QTimer::timeout, this, &JoystickController::pollJoystick);
}

JoystickController::~JoystickController() {
    stop();

    // Корректное завершение SDL2
    if (m_joystick) {
        SDL_JoystickClose(m_joystick);
        m_joystick = nullptr;
    }
    SDL_Quit();
}

bool JoystickController::initialize(int deviceIndex) {
    m_deviceIndex = deviceIndex;

    // Инициализация SDL2 (только подсистема джойстика)
    if (SDL_Init(SDL_INIT_JOYSTICK) < 0) {
        QString error = QString("SDL_Init failed: %1").arg(SDL_GetError());
        emit errorOccurred(error);
        qDebug() << "❌" << error;
        return false;
    }

    // Проверка наличия джойстиков
    int numJoysticks = SDL_NumJoysticks();
    if (numJoysticks == 0) {
        emit errorOccurred("Джойстики не найдены. Подключите устройство.");
        qDebug() << "❌ Джойстики не найдены";
        SDL_Quit();
        return false;
    }

    if (deviceIndex >= numJoysticks) {
        emit errorOccurred(QString("Джойстик %1 не найден (доступно: %2)")
                               .arg(deviceIndex).arg(numJoysticks));
        SDL_Quit();
        return false;
    }

    // Открытие джойстика
    m_joystick = SDL_JoystickOpen(deviceIndex);
    if (!m_joystick) {
        QString error = QString("SDL_JoystickOpen failed: %1").arg(SDL_GetError());
        emit errorOccurred(error);
        qDebug() << "❌" << error;
        SDL_Quit();
        return false;
    }

    // Получение информации об устройстве
    QString name = SDL_JoystickName(m_joystick);
    int axes = SDL_JoystickNumAxes(m_joystick);
    int buttons = SDL_JoystickNumButtons(m_joystick);

    qDebug() << "✅ Джойстик подключён:" << name;
    qDebug() << "   Оси:" << axes << "| Кнопки:" << buttons;

    // Инициализация кэша состояния
    m_axes.resize(axes, 0);
    m_buttons.resize(buttons, 0);
    m_isConnected = true;

    emit connected(name);
    return true;
}

void JoystickController::start(int pollIntervalMs) {
    if (m_isConnected && m_joystick) {
        m_pollTimer->start(pollIntervalMs);
        qDebug() << "▶ Опрос джойстика запущен (" << pollIntervalMs << "ms)";
    }
}

void JoystickController::stop() {
    if (m_pollTimer->isActive()) {
        m_pollTimer->stop();
        qDebug() << "⏹ Опрос джойстика остановлен";
    }
}

QString JoystickController::deviceName() const {
    if (m_joystick) {
        return QString(SDL_JoystickName(m_joystick));
    }
    return "Не подключён";
}

int JoystickController::axisValue(int index) const {
    if (index >= 0 && index < static_cast<int>(m_axes.size())) {
        return m_axes[index];
    }
    return 0;
}

bool JoystickController::isButtonPressed(int index) const {
    if (index >= 0 && index < static_cast<int>(m_buttons.size())) {
        return m_buttons[index] != 0;
    }
    return false;
}

bool JoystickController::isSignificantChange(short oldVal, short newVal) const {
    return qAbs(newVal - oldVal) > m_deadzone;
}

void JoystickController::pollJoystick() {
    // Обработка событий SDL2
    SDL_JoystickUpdate();

    if (!m_joystick || !SDL_JoystickGetAttached(m_joystick)) {
        // Джойстик был отключён
        m_isConnected = false;
        emit disconnected();
        stop();
        qDebug() << "🔌 Джойстик отключён";
        return;
    }

    // Опрос осей
    for (size_t i = 0; i < m_axes.size(); ++i) {
        short newValue = SDL_JoystickGetAxis(m_joystick, static_cast<int>(i));
        if (isSignificantChange(m_axes[i], newValue)) {
            m_axes[i] = newValue;
            emit axisChanged(static_cast<int>(i), newValue);

            // Формируем команду для отправки
            QVariantMap data{
                {"axis", static_cast<int>(i)},
                {"value", newValue},
                {"normalized", static_cast<double>(newValue) / 32768.0},
                {"timestamp", QDateTime::currentMSecsSinceEpoch()}
            };
            emit commandReady("axis", data);
        }
    }

    // Опрос кнопок
    for (size_t i = 0; i < m_buttons.size(); ++i) {
        unsigned char newValue = SDL_JoystickGetButton(m_joystick, static_cast<int>(i));
        if (newValue != m_buttons[i]) {
            bool pressed = (newValue != 0);
            m_buttons[i] = newValue;

            if (pressed) {
                emit buttonPressed(static_cast<int>(i));
            } else {
                emit buttonReleased(static_cast<int>(i));
            }

            // Формируем команду для отправки
            QVariantMap data{
                {"button", static_cast<int>(i)},
                {"pressed", pressed},
                {"timestamp", QDateTime::currentMSecsSinceEpoch()}
            };
            emit commandReady(pressed ? "button_press" : "button_release", data);
        }
    }
}
