//
//  Funcao_04.hpp
//  IntegracaoNumerica
//
//  Created by cvidal on 3/12/17.
//  Copyright © 2017 CRAb. All rights reserved.
//

#ifndef Funcao_04_hpp
#define Funcao_04_hpp

#include <math.h>

#include "Funcao.hpp"

class Funcao_04 : public Funcao
{
public:
    double f(double x)
    {
        return (sin(x));
    }
};


#endif /* Funcao_04_hpp */
