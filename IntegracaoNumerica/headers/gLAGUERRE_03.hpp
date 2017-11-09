//
//  gLAGUERRE_03.hpp
//  IntegracaoNumerica
//
//  Created by cvidal on 3/24/17.
//  Copyright © 2017 CRAb. All rights reserved.
//

#ifndef gLAGUERRE_03_hpp
#define gLAGUERRE_03_hpp

#include "Integracao.hpp"

class gLAGUERRE_03 : public Integracao
{
public:
    gLAGUERRE_03(Funcao * f);

    virtual double integrar();

private:
    double  gLAGUERRE_03_integracao();

    Funcao *m_pIntegrando;

};


#endif /* gLAGUERRE_03_hpp */
