#include <iostream>
#include <random>
#include <vector>
#include <list>
#include <functional>
#include <algorithm>
#include "redeneural.h"

using namespace std;

int main()
{

   libRedeN::RedeNeural *rede = new libRedeN::RedeNeural();

       rede->iMA_buf.push_back(1);
       rede->iMA_buf.push_back(0);
       rede->iMA_buf.push_back(1);

       rede->weight.push_back(100);
       rede->weight.push_back(50);
       rede->weight.push_back(50);

       rede->setWeight(rede->weight);

       rede->calculaNet(rede->normalizacao(rede->iMA_buf),rede->weight);

       cout <<  rede->funcaoDePasso(rede->getNET())  << endl;
       cout <<  rede->funcaoSignoide(rede->getNET()) << endl;
       cout <<  rede->funcaoHiperbolica(rede->getNET()) << endl;

    return 0;
}
