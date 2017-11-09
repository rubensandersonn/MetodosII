//
//  Funcao_R2_imp.hpp
//  IntegracaoNumerica
//
//  Created by cvidal on 3/12/17.
//  Copyright © 2017 CRAb. All rights reserved.
//

#ifndef Funcao_R2_imp_hpp
#define Funcao_R2_imp_hpp

#include "Funcao_R2.hpp"
#include <math.h>

class Funcao_R2_imp : public Funcao_R2
{
public:
	Funcao_R2_imp (){
	}

    double f(double x, double y)
    {

		return 2 * y * sin(x) + pow(cos(x), 2);

    }

};


#endif /* Funcao_R2_imp_hpp */
