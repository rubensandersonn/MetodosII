//
//  X_R2.hpp
//  IntegracaoNumerica
//
//  Created by cvidal on 3/12/17.
//  Copyright © 2017 CRAb. All rights reserved.
//

#ifndef X_R2_imp_hpp
#define X_R2_imp_hpp

#include "X_R2.hpp"
#include "IntegralDupla.hpp"
#include <math.h>

class X_R2 : public Funcao_R2
{
public:
  X_R2 (double a, double b){
  	b_func = b;
  	a_func = a;
  }

    double f(double s, double t)
    {

        return ((b_func + a_func)/2) + ((b_func - a_func)/2) * s;

    }
private:
	double b_func;
  	double a_func;
};


#endif /* X_R2_imp_hpp */
