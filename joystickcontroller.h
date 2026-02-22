#ifndef JOYSTICKCONTROLLER_H
#define JOYSTICKCONTROLLER_H

#include <QObject>
#include <QTimer>
#include <QVariantMap>
#include <vector>

// Предварительные объявления SDL2 (чтобы не тянуть весь заголовок в .h)
    struct _SDL_Joystick;
typedef struct _SDL_Joystick SDL_Joystick;

/**
 * @brief Контроллер джойстика на базе SDL2
 *
 * Работает независимо от Qt — можно использовать вместе с любым интерфейсом
 */
class JoystickController : public QObject {
    Q_OBJECT

public:
    explicit JoystickController(QObject *parent = nullptr);
    ~JoystickController();

    // Управление
    bool initialize(int deviceIndex = 0);
    void start(int pollIntervalMs = 20); // 50 FPS опрос
    void stop();
    bool isConnected() const { return m_isConnected; }

    // Информация об устройстве
    QString deviceName() const;
    int axisCount() const { return static_cast<int>(m_axes.size()); }
    int buttonCount() const { return static_cast<int>(m_buttons.size()); }

    // Текущее состояние
    int axisValue(int index) const;
    bool isButtonPressed(int index) const;

    // Порог чувствительности (игнорировать дрожание)
    void setDeadzone(int value) { m_deadzone = value; }
    int deadzone() const { return m_deadzone; }

signals:
    // Сигналы для интеграции с Qt
    void connected(const QString &name);
    void disconnected();
    void errorOccurred(const QString &message);

    void axisChanged(int axisIndex, int value);
    void buttonPressed(int buttonIndex);
    void buttonReleased(int buttonIndex);

    // Универсальный сигнал для отправки команд
    void commandReady(const QString &commandType, const QVariantMap &data);

private slots:
    void pollJoystick(); // Слот для таймера

private:
    SDL_Joystick *m_joystick = nullptr;
    int m_deviceIndex = 0;
    bool m_isConnected = false;
    int m_deadzone = 3000; // Порог для осей (диапазон ±32768)

    // Кэширование состояния
    std::vector<short> m_axes;
    std::vector<unsigned char> m_buttons;

    QTimer *m_pollTimer = nullptr;

    // Вспомогательные методы
    bool isSignificantChange(short oldVal, short newVal) const;
    void updateState();
};

#endif // JOYSTICKCONTROLLER_H
