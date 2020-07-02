#pragma once

#include <iostream>
#include <QObject>
#include <QVector>
#include <QDebug>
#include <memory>

#include "redeneural.h"
using namespace std;

enum class tipo
{
   FUNCAODEPASSO = 1,
   SIGNOIDE = 2 ,
   FUNCAOHIPERBOLICA =3
};


class neuronio : public QObject
{
    Q_OBJECT
public:

    explicit neuronio(QObject *parent = nullptr);
    double defineNeuronio(libRedeN::RedeNeural *rede);

private:



signals:

};
