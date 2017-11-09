//
//  Funcao_02.hpp
//  IntegracaoNumerica
//
//  Created by cvidal on 3/12/17.
//  Copyright © 2017 CRAb. All rights reserved.
//

#ifndef Funcao_02_hpp
#define Funcao_02_hpp

#include "Funcao.hpp"

class Funcao_02 : public Funcao
{
public:
    double f(double x)
    {
        return (x*x*x);
    }
};


#endif /* Funcao_02_hpp */
