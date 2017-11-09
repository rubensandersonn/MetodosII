//
//  Hx.hpp
//  IntegracaoNumerica
//
//  Created by cvidal on 3/12/17.
//  Copyright © 2017 CRAb. All rights reserved.
//

#ifndef Hx_hpp
#define Hx_hpp

#include "Funcao.hpp"
#include <math.h>

class Hx : public Funcao
{
public:
    double f(double x)
    {
        return exp(- pow(x,2) ) * F->f(x);
    }
};


#endif /* Hx_hpp */
