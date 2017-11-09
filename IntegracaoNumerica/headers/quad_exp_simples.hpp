//
//  quad_exp_simples.hpp
//  IntegracaoNumerica
//
//  Created by cvidal on 3/24/17.
//  Copyright © 2017 CRAb. All rights reserved.
//

#ifndef quad_exp_simples_hpp
#define quad_exp_simples_hpp

#include "Integracao.hpp"

class quad_exp_simples : public Integracao
{
public:
    quad_exp_simples(Funcao * f, double a, double b, double epsilon);

    virtual double integrar();

private:
    double  quad_exp_simples_integracao(double a, double b);

    Funcao * F;

    double b_func, a_func;

    double epsilon_func;
};


#endif /* quad_exp_simples_hpp */
