//
//  gLAGUERRE_04.hpp
//  IntegracaoNumerica
//
//  Created by cvidal on 3/24/17.
//  Copyright © 2017 CRAb. All rights reserved.
//

#ifndef gLAGUERRE_04_hpp
#define gLAGUERRE_04_hpp

#include "Integracao.hpp"

class gLAGUERRE_04 : public Integracao
{
public:
    gLAGUERRE_04(Funcao * f);

    virtual double integrar();

private:
    double  gLAGUERRE_04_integracao();

    Funcao *m_pIntegrando;

};


#endif /* gLAGUERRE_04_hpp */
