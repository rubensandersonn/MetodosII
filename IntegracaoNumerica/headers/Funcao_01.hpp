//
//  Funcao_01.hpp
//  IntegracaoNumerica
//
//  Created by cvidal on 3/12/17.
//  Copyright © 2017 CRAb. All rights reserved.
//

#ifndef Funcao_01_hpp
#define Funcao_01_hpp

#include "Funcao.hpp"

class Funcao_01 : public Funcao
{
public:
    double f(double x)
    {
        return (x*x);
    }
};

#endif /* Funcao_01_hpp */
