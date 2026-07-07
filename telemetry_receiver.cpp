#include "telemetry_receiver.h"

#include <QSerialPort>
#include <cstring>

TelemetryReceiver::TelemetryReceiver(QObject *parent)
    : QObject(parent)
{
}

TelemetryReceiver::~TelemetryReceiver()
{
    closePort();
}

void TelemetryReceiver::openPort(const QString &portName, qint32 baudRate)
{
    closePort();

    m_port = new QSerialPort(this);
    m_port->setPortName(portName);
    m_port->setBaudRate(baudRate);
    m_port->setDataBits(QSerialPort::Data8);
    m_port->setParity(QSerialPort::NoParity);
    m_port->setStopBits(QSerialPort::OneStop);
    m_port->setFlowControl(QSerialPort::NoFlowControl);

    if (!m_port->open(QIODevice::ReadOnly)) {
        emit errorOccurred(tr("Не удалось открыть %1: %2").arg(portName, m_port->errorString()));
        delete m_port;
        m_port = nullptr;
        return;
    }

    m_buffer.clear();
    connect(m_port, &QSerialPort::readyRead, this, &TelemetryReceiver::onReadyRead);
    emit connected();
}

void TelemetryReceiver::closePort()
{
    if (!m_port)
        return;

    m_port->close();
    delete m_port;
    m_port = nullptr;
    m_buffer.clear();
    emit disconnected();
}

void TelemetryReceiver::onReadyRead()
{
    m_buffer.append(m_port->readAll());
    parseBuffer();
}

void TelemetryReceiver::parseBuffer()
{
    static const char preamble[PACKET_PREAMBLE_LEN] = {
        char(PACKET_PREAMBLE_BYTE0), char(PACKET_PREAMBLE_BYTE1)
    };

    for (;;) {
        const int start = m_buffer.indexOf(QByteArray(preamble, PACKET_PREAMBLE_LEN));
        if (start < 0) {
            // Преамбулы нет вовсе — оставляем только последний байт (вдруг это её начало)
            if (m_buffer.size() > 1)
                m_buffer = m_buffer.right(1);
            return;
        }
        if (start > 0)
            m_buffer.remove(0, start);

        if (m_buffer.size() < static_cast<int>(sizeof(PacketHeader_t)))
            return; // ждём байт типа пакета

        const quint8 type = static_cast<quint8>(m_buffer.at(2));
        int packetSize;
        switch (type) {
        case PACKET_TYPE_TELEMETRY:
            packetSize = sizeof(TelemetryPacket_t);
            break;
        default:
            // Неизвестный тип — это была не настоящая преамбула, пропускаем её и ищем дальше
            m_buffer.remove(0, PACKET_PREAMBLE_LEN);
            continue;
        }

        if (m_buffer.size() < packetSize)
            return; // пакет ещё не пришёл целиком

        const auto *tail = reinterpret_cast<const uint8_t *>(
            m_buffer.constData() + packetSize - PACKET_TAIL_LEN);
        if (tail[0] != PACKET_TAIL_BYTE0 || tail[1] != PACKET_TAIL_BYTE1) {
            m_buffer.remove(0, PACKET_PREAMBLE_LEN);
            continue;
        }

        TelemetryPacket_t packet;
        std::memcpy(&packet, m_buffer.constData(), sizeof(TelemetryPacket_t));
        emit frameReceived(packet.payload);

        m_buffer.remove(0, packetSize);
    }
}
