#include "redeneural.h"

libRedeN::RedeNeural::RedeNeural()
{
   setD1(0);
   setD2(1);
   setX_max(0);
   setX_min(0);
}

libRedeN::RedeNeural::~RedeNeural()
{
    delete this;
}

QVector <double> libRedeN::RedeNeural::normalizacao(QVector<double> iMA_buf)
{

    this->iMA_buf=iMA_buf;

    sort(iMA_buf.begin(),iMA_buf.end());

    for(int i=0 ; i < iMA_buf.size() ; i++)
    {
        if(iMA_buf[i] > getX_max())
        {
            setX_max(iMA_buf[i]);
        }

        if(iMA_buf[i] < getX_min())
        {
            setX_min(iMA_buf[i]);
        }
    }

    setValorMaximo(getX_max());
    setValorMinimo(getX_min());

    for(int i=0 ; i < iMA_buf.size(); i++)
    {
        inputs=(((iMA_buf[i]-getValorMinimo())*(d2-d1))/(getValorMaximo()-getValorMinimo()))+d1;
        imputX.push_back(inputs);
    }

    return imputX;
}

double libRedeN::RedeNeural::calculaNet(QVector <double> imputX, QVector <double> weight)
{
    this->imputX =imputX;
    this->weight = weight;
    for(int n=0;n<imputX.size();n++)
    {
        NET+=(this->imputX.at(n)*this->weight.at(n));
    }

    if(NET > 2)
    {
        NET*=0.4;
    }
    return NET;
}

double libRedeN::RedeNeural::funcaoDePasso(double NET)
{
    this->NET = NET;

    if(NET > 2) {
        out=1;
    }
    else
    {
        out=0;
    }

    return out;
}

double libRedeN::RedeNeural::funcaoSignoide(double NET)
{
    this->NET = NET;
    out = 1/(1+exp(-NET));
    return out;
}

double libRedeN::RedeNeural::funcaoHiperbolica(double NET)
{
    this->NET = NET;
    out = (exp(NET)-exp(-NET))/(exp(NET)+exp(-NET));
    return out;
}


double libRedeN::RedeNeural::getX_max() const
{
    return x_max;
}

void libRedeN::RedeNeural::setX_max(double value)
{
    x_max = value;
}

double libRedeN::RedeNeural::getEntrada_x0() const
{
    return entrada_x0;
}

void libRedeN::RedeNeural::setEntrada_x0(double value)
{
    entrada_x0 = value;
}

QVector<double> libRedeN::RedeNeural::getWeight() const
{
    return weight;
}

void libRedeN::RedeNeural::setWeight(const QVector<double> &value)
{
    weight = value;
}

double libRedeN::RedeNeural::getOut() const
{
    return out;
}

void libRedeN::RedeNeural::setOut(double value)
{
    out = value;
}

double libRedeN::RedeNeural::getValorMinimo() const
{
    return valorMinimo;
}

void libRedeN::RedeNeural::setValorMinimo(double value)
{
    valorMinimo = value;
}

double libRedeN::RedeNeural::getD1() const
{
    return d1;
}

void libRedeN::RedeNeural::setD1(double value)
{
    d1 = value;
}

double libRedeN::RedeNeural::getD2() const
{
    return d2;
}

void libRedeN::RedeNeural::setD2(double value)
{
    d2 = value;
}

double libRedeN::RedeNeural::getInputs() const
{
    return inputs;
}

void libRedeN::RedeNeural::setInputs(double value)
{
    inputs = value;
}

double libRedeN::RedeNeural::getNET() const
{
    return NET;
}

void libRedeN::RedeNeural::setNET(double value)
{
    NET = value;
}

double libRedeN::RedeNeural::getValorMaximo() const
{
    return valorMaximo;
}

void libRedeN::RedeNeural::setValorMaximo(double value)
{
    valorMaximo = value;
}

double libRedeN::RedeNeural::getX_min() const
{
    return x_min;
}

void libRedeN::RedeNeural::setX_min(double value)
{
    x_min = value;
}
