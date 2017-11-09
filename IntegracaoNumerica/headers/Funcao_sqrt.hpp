//
//  Funcao_sqrt.hpp
//  IntegracaoNumerica
//
//  Created by cvidal on 3/12/17.
//  Copyright © 2017 CRAb. All rights reserved.
//

#ifndef Funcao_sqrt_hpp
#define Funcao_sqrt_hpp

#include <math.h>

#include "Funcao.hpp"

class Funcao_sqrt : public Funcao
{
public:
    double f(double x)
    {
        return sqrt(1 + (1/x)); // [0,2] = 3.59571
    }
};


#endif /* Funcao_sqrt_hpp */
