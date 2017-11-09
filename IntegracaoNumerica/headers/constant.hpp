//
//  constant.hpp
//  IntegracaoNumerica
//
//  Created by cvidal on 3/12/17.
//  Copyright © 2017 CRAb. All rights reserved.
//

#ifndef constant_hpp
#define constant_hpp

#include <math.h>

#include "Funcao.hpp"

class constant : public Funcao
{
public:
	constant(double x){
		c = x;
	}
    double f(double x)
    {
        return c; // [0,2] = 3.59571
    }
private:
	double c;
};


#endif /* constant_hpp */
