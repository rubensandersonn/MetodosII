//
//  Funcao_semiesfera_imp.hpp
//  IntegracaoNumerica
//
//  Created by cvidal on 3/12/17.
//  Copyright © 2017 CRAb. All rights reserved.
//

#ifndef Funcao_semiesfera_hpp
#define Funcao_semiesfera_hpp

#include "Funcao_R2.hpp"
#include <math.h>

class Funcao_semiesfera : public Funcao_R2
{
public:
	Funcao_semiesfera (){
	}

    double f(double x, double y)
    {

		return pow(100 - (x*x + y*y), 0.5);

    }

};


#endif /* Funcao_semiesfera_imp_hpp */
