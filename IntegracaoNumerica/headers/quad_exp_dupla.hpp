//
//  quad_exp_dupla.hpp
//  IntegracaoNumerica
//
//  Created by cvidal on 3/24/17.
//  Copyright © 2017 CRAb. All rights reserved.
//

#ifndef quad_exp_dupla_hpp
#define quad_exp_dupla_hpp

#include "Integracao.hpp"

class quad_exp_dupla : public Integracao
{
public:
    quad_exp_dupla(Funcao * f, double a, double b, double epsilon);

    virtual double integrar();

private:
    double  quad_exp_dupla_integracao(double a, double b);

    Funcao * F;

    double b_func, a_func;

    double epsilon_func;
};


#endif /* quad_exp_dupla_hpp */
