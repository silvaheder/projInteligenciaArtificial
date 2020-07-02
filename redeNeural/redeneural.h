#pragma once

#include <QObject>
#include <QVector>
#include <iostream>
#include <cstdlib>
#include <QtMath>
#include <QDebug>

using namespace std;
namespace libRedeN {

class  RedeNeural
{
public:
            RedeNeural();
   virtual ~RedeNeural();
   double calculaNet(QVector <double> imputX, QVector <double> weight);
   double funcaoDePasso(double NET);
   double funcaoSignoide(double NET);
   double funcaoHiperbolica(double NET);
   QVector <double> normalizacao(QVector <double> iMA_buf);

   double getX_min() const;
   void setX_min(double value);

   double getX_max() const;
   void setX_max(double value);


   double getEntrada_x0() const;
   void setEntrada_x0(double value);

   QVector <double> iMA_buf;
   QVector <double> imputX;
   QVector <double> weight;
   QVector <double> grafico;

   double getPosicaoMaior() const;
   void setPosicaoMaior(double value);

   double getPosicaoMenor() const;
   void setPosicaoMenor(double value);

   double getValorMaximo() const;
   void setValorMaximo(double value);

   double getValorMinimo() const;
   void setValorMinimo(double value);

   double getD0() const;
   void setD0(double value);

   double getD1() const;
   void setD1(double value);

   double getD2() const;
   void setD2(double value);

   double getInputs() const;
   void setInputs(double value);

   double getNET() const;
   void setNET(double value);

   QVector<double> getWeight() const;
   void setWeight(const QVector<double> &value);

   double getOut() const;
   void setOut(double value);

private:
   double x_min;
   double x_max;
   double inputs;
   double out;
   double NET;
   double result;

   double d1;
   double d2;

   double entrada_x0;

   double valorMaximo;
   double valorMinimo;

private slots:

 };

}

