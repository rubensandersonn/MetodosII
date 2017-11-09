//
//  IntegralDupla.hpp
//  IntegracaoNumerica
//
//  Created by cvidal on 3/24/17.
//  Copyright © 2017 CRAb. All rights reserved.
//

#ifndef IntegralDupla_hpp
#define IntegralDupla_hpp

#include "Integracao.hpp"
#include <iostream>

using namespace std;

class IntegralDupla : public Integracao
{
public:
    IntegralDupla(Funcao_R2 * f, double a, double b, Funcao * c, Funcao * d, int na, int nb);

    virtual double integrar();

private:
    double  IntegralDupla_integracao();

    Funcao_R2 * F;

   Funcao * C;
   Funcao * D;

   int nAlpha;
   int nBetha;

   double valida(double s);

    double derivada_R2(Funcao_R2 * func, double alp, double bet, double delta, double lim_sup, double lim_inf, int emRelacaoA);

    double derivada(Funcao * func, double alp, double delta);

    double detJacob(double alpha, double betha);

    double b_func; double a_func;

    double X(double s, double t);

    double Y(double s, double t);
};


#endif /* IntegralDupla_hpp */
