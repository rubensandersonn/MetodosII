//
//  gLAGUERRE_02.hpp
//  IntegracaoNumerica
//
//  Created by cvidal on 3/24/17.
//  Copyright © 2017 CRAb. All rights reserved.
//

#ifndef gLAGUERRE_02_hpp
#define gLAGUERRE_02_hpp

#include "Integracao.hpp"

class gLAGUERRE_02 : public Integracao
{
public:
    gLAGUERRE_02(Funcao * f);

    virtual double integrar();

private:
    double  gLAGUERRE_02_integracao();

    Funcao *m_pIntegrando;

};


#endif /* gLAGUERRE_02_hpp */
