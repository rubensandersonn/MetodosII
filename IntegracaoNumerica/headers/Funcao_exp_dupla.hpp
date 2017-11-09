//
//  Funcao_exp_dupla.hpp
//  IntegracaoNumerica
//
//  Created by cvidal on 3/12/17.
//  Copyright © 2017 CRAb. All rights reserved.
//

#ifndef Funcao_exp_dupla_hpp
#define Funcao_exp_dupla_hpp

#include "Funcao.hpp"
#include <math.h>

class Funcao_exp_dupla : public Funcao
{
public:
	Funcao_exp_dupla (Funcao * g, double a, double b){
		b_func = b;
		a_func = a;
		F = g;
	}

    double f(double x)
    {

      return F->f(xs(x)) * ((b_func - a_func)/2)* (1 - pow(tanh( u(x) ), 2)) * (3.1416 / 2) * cosh(x);
    }
 private:
 	Funcao * F;

 	double b_func, a_func;


 	double xs(double s){
 		return ((b_func + a_func)/2) + ((b_func - a_func)/2) * tanh ( u(s) );
 	}

 	double u(double x){
 		return (3.1416 /2) * (sinh(x));
 	}
};


#endif /* Funcao_exp_dupla_hpp */
