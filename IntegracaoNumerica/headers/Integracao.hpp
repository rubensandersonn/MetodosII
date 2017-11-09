//
//  Integracao.hpp
//  IntegracaoNumerica
//
//  Created by cvidal on 3/12/17.
//  Copyright © 2017 CRAb. All rights reserved.
//

#ifndef Integracao_hpp
#define Integracao_hpp

#include "Funcao.hpp"
#include "Funcao_R2.hpp"


class Integracao
{
public:

    virtual double integrar() = 0;

};

#endif /* Integracao_hpp */
