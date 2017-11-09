//
//  Funcao_exp_simples.hpp
//  IntegracaoNumerica
//
//  Created by cvidal on 3/12/17.
//  Copyright © 2017 CRAb. All rights reserved.
//

#ifndef Funcao_exp_simples_hpp
#define Funcao_exp_simples_hpp

#include "Funcao.hpp"
#include <math.h>
#include <iostream>

using namespace std;

class Funcao_exp_simples : public Funcao
{
public:
	Funcao_exp_simples (Funcao * g, double a, double b){
		b_func = b;
		a_func = a;
		F = g;
	}

    double f(double x)
    {
    	double fxs = F->f(xs(x));
    	double bminusadiv2 = ((b_func - a_func)/2);
    	double t = (1- pow(tanh(x), 2));

    	//cout << "\n 	Dados dentro de funcao_exp_simples_hpp: fxs = " << fxs << " , (b - a) /2 = " << bminusadiv2 << " , 1 - tanh^2(x) = " << t << endl;

       return  fxs * bminusadiv2 * t;
    }
 private:
 	Funcao * F;

 	double b_func, a_func;


 	double xs(double s){

 		return ((b_func + a_func)/2) + ((b_func - a_func)/2) * tanh (s);
 	}
};


#endif /* Funcao_exp_simples_hpp */
