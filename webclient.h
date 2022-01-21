#ifndef WEBCLIENT_H
#define WEBCLIENT_H

#include "ui_webclient.h"

class Webclient : public QWidget, private Ui::Webclient
{
    Q_OBJECT

public:
    explicit Webclient(QWidget *parent = nullptr);
};

#endif // WEBCLIENT_H
