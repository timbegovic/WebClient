#ifndef WEBCLIENT_H
#define WEBCLIENT_H

#include "ui_webclient.h"
#include <QDebug>
#include <QAbstractSocket>
#include <QTcpSocket>

class Webclient : public QWidget, private Ui::Webclient
{
    Q_OBJECT

public:
    explicit Webclient(QWidget *parent = nullptr);

private slots:
    void gobutton_clicked();

private:
    void connectsocket();
    void outputMessage(QString message);
    void disconnect();

private:
    QTcpSocket *m_socket = nullptr;
    QString m_search;
    const char m_port = 80;
};

#endif // WEBCLIENT_H
