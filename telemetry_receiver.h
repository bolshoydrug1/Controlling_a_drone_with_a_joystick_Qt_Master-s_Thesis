#ifndef TELEMETRY_RECEIVER_H
#define TELEMETRY_RECEIVER_H

#include <QObject>
#include <QByteArray>
#include <QMetaType>

extern "C" {
#include "Telemetry_Data.h"
}

class QSerialPort;

/**
 * @brief Живёт в отдельном QThread: держит открытый QSerialPort, копит
 * входящие байты и вырезает из них пакеты телеметрии (см. Telemetry_Data.h).
 */
class TelemetryReceiver : public QObject
{
    Q_OBJECT

public:
    explicit TelemetryReceiver(QObject *parent = nullptr);
    ~TelemetryReceiver() override;

public slots:
    void openPort(const QString &portName, qint32 baudRate);
    void closePort();

signals:
    void frameReceived(TelemetryFrame_t frame);
    void connected();
    void disconnected();
    void errorOccurred(const QString &message);

private slots:
    void onReadyRead();

private:
    void parseBuffer();

    QSerialPort *m_port = nullptr;
    QByteArray m_buffer;
};

Q_DECLARE_METATYPE(TelemetryFrame_t)

#endif // TELEMETRY_RECEIVER_H
