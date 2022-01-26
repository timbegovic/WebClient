#include "webclient.h"
#include <thread>

Webclient::Webclient(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);


    connect(hostname, &QLineEdit::returnPressed, this, &Webclient::gobutton_clicked);

    m_socket = new QTcpSocket(this);
    connect(m_socket, &QTcpSocket::connected, this, &Webclient::connectsocket);
    connect(m_socket, &QTcpSocket::readyRead, this, &Webclient::disconnect);
    connect(gobutton, &QPushButton::clicked, this, &Webclient::gobutton_clicked);


}

void Webclient::outputMessage(QString message)
{
    outputmessage->clear();
    outputmessage->setText(message);
}

void Webclient::connectsocket()
{
    m_socket->write(QString("GET / HTTP/1.1\r\nHost:" + m_search + "\r\n\r\n").toLocal8Bit());
}

void Webclient::disconnect()
{
    outputMessage(m_socket->readAll());
    m_socket->disconnectFromHost();
}

void Webclient::gobutton_clicked()
{

    if(hostname->text().isEmpty())
    {
        outputMessage("Couldn't find adress.");
    }
    else
    {
        m_socket->connectToHost(hostname->text(), m_port);
    }
}
