#include "udpworker.h"

UDPworker::UDPworker(QObject *parent) : QObject(parent) {}

/*!
 * @brief Метод инициализирует UDP сервер
 */
void UDPworker::InitSocket(int bindPort)
{
    bindPort_ = bindPort;
    serviceUdpSocket = new QUdpSocket(this);
    /*
     * Соединяем присваиваем адрес и порт серверу и соединяем функцию
     * обработчик принятых пакетов с сокетом
     */
    serviceUdpSocket->bind(QHostAddress::LocalHost, bindPort_);

    connect(serviceUdpSocket, &QUdpSocket::readyRead, this, &UDPworker::readPendingDatagrams);

}

/*!
 * @brief Метод осуществляет обработку принятой датаграммы
 */
void UDPworker::ReadDatagram(QNetworkDatagram datagram)
{

    QByteArray data;
    data = datagram.data();

    QDataStream inStr(&data, QIODevice::ReadOnly);
    if (bindPort_ == 12345)
    {
        QDateTime dateTime;
        inStr >> dateTime;
        emit sig_sendTimeToGUI(dateTime);
    }
    else if(bindPort_ == 3000) //исправлен номер порта
    {
        QString dateInputText;
        inStr >> dateInputText;
        QString localAddress = serviceUdpSocket->localAddress().toString();
        emit sig_sendInputTextToGUI(dateInputText, localAddress, bindPort_);
    }
}
/*!
 * @brief Метод осуществляет опередачу датаграммы
 */
void UDPworker::SendDatagram(QByteArray data)
{
    /*
     *  Отправляем данные на localhost и задефайненный порт
     */
    serviceUdpSocket->writeDatagram(data, QHostAddress::LocalHost, bindPort_);
}

/*!
 * @brief Метод осуществляет чтение датаграм из сокета
 */
void UDPworker::readPendingDatagrams( void )
{
    /*
     *  Производим чтение принятых датаграмм
     */
    while(serviceUdpSocket->hasPendingDatagrams()){
            QNetworkDatagram datagram = serviceUdpSocket->receiveDatagram();
            ReadDatagram(datagram);
    }

}
