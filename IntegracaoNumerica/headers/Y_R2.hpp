//
//  Y_R2.hpp
//  IntegracaoNumerica
//
//  Created by cvidal on 3/12/17.
//  Copyright © 2017 CRAb. All rights reserved.
//

#ifndef Y_R2_imp_hpp
#define Y_R2_imp_hpp

#include "Y_R2.hpp"
#include <math.h>

class Y_R2 : public Funcao_R2
{
public:
  Y_R2 (Funcao * c, Funcao * d, X_R2 * x){
  	C = c;
  	D = d;
  	X = x;
  }

    double f(double s, double t)
    {

        return (C->f(X->f(s,t)) + D->f(X->f(s,t)) )/2 + ((D->f(X->f(s,t)) - C->f(X->f(s,t)) )/2) * t;

    }
private :
	Funcao * C;
	Funcao * D;
	X_R2 * X;

};


#endif /* Y_R2_imp_hpp */
