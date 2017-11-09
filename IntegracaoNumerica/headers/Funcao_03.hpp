//
//  Funcao_03.hpp
//  IntegracaoNumerica
//
//  Created by cvidal on 3/12/17.
//  Copyright © 2017 CRAb. All rights reserved.
//

#ifndef Funcao_03_hpp
#define Funcao_03_hpp

#include <math.h>

#include "Funcao.hpp"

class Funcao_03 : public Funcao
{
public:
    double f(double x)
    {
        return (cos(x));
    }
};


#endif /* Funcao_03_hpp */
