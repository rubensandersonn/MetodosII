//
//  IntegralDupla_q5.hpp
//  IntegracaoNumerica
//
//  Created by cvidal on 3/24/17.
//  Copyright © 2017 CRAb. All rights reserved.
//

#ifndef IntegralDupla_q5_hpp
#define IntegralDupla_q5_hpp

#include "Integracao.hpp"
#include <iostream>

using namespace std;

class IntegralDupla_q5 : public Integracao
{
public:
    IntegralDupla_q5(Funcao_R2 * f, double a, double b, Funcao * c, Funcao * d, int na, int nb, Funcao_R2 * x, Funcao_R2 * y);

    virtual double integrar();

private:
    double  IntegralDupla_q5_integracao();

    Funcao_R2 * F;
    Funcao_R2 * X;
    Funcao_R2 * Y;

   Funcao * C;
   Funcao * D;

   int nAlpha;
   int nBetha;

   double valida(double s);

    double derivada_R2(Funcao_R2 * func, double alp, double bet, double delta, double lim_sup, double lim_inf, int emRelacaoA);

    double derivada(Funcao * func, double alp, double delta);

    double detJacob(double alpha, double betha);

    double b_func; double a_func;
};


#endif /* IntegralDupla_q5_hpp */
